/*
    Copyright 2022 r-neal-kelly
*/

`use strict`;

import * as path from "path";

import
{
    Read_Directory,
    Write_File,
    Print_Error,
} from "./common.js"

const /* string_t */ lists_file_name = `CMakeLists.txt`;
const /* string_t */ min_cmake_version = `3.18`;
const /* string_t */ help_message = `
Info:

    Will create a "${lists_file_name}" file for all parts of the library.
    The file will properly include each header and source file.

Parameter #1:

    relative or absolute path, e.g. "../../":
        Must be the top folder in the nkr repository.
    
    "-h" or "--help" or (none):
        Displays this message in the terminal.
`;

/*
    Recursively gets a list of all file names resolved by the passed in path. Excludes any directories.
*/
/* string_t[] */ async function Directory_File_Names(/* string_t */ directory_path, /* string_t */ directory_name)
{
    async function Accumulate(/* string_t */ directory_path, /* string_t[] */ directory_name, /* string_t[] */ file_names)
    {
        try {
            const /* fs.Dirent[] */ entities = await Read_Directory(directory_path);

            for (let /* fs.Dirent */ entity of entities) {
                if (entity.isDirectory()) {
                    await Accumulate(`${directory_path}/${entity.name}`, `${directory_name}/${entity.name}`, file_names);
                } else if (entity.isFile()) {
                    file_names.push(`${directory_name}/${entity.name}`);
                }
            }
        } catch (error) {
            Print_Error(`failed to read directory: ${directory_path}`, error);
        }
    }

    let /* string_t[] */ file_names = [];
    await Accumulate(directory_path, directory_name, file_names);
    if (file_names.length > 0) {
        return file_names;
    } else {
        return null;
    }
}

/*
    Generates an object containing two arrays of file names, one for includes and one for sources.
*/
/* { include_file_names: string_t[], source_file_names: string_t[] } */
async function Include_And_Source_File_Names(/* string_t */ directory_path,
                                             /* string_t */ include_directory_name = `include`,
                                             /* string_t */ source_directory_name = `src`)
{
    try {
        const /* fs.Dirent[] */ entities = await Read_Directory(directory_path);
        let /* fs.Dirent */ include_directory = null;
        let /* fs.Dirent */ source_directory = null;

        for (let /* fs.Dirent */ entity of entities) {
            if (entity.isDirectory()) {
                if (entity.name === include_directory_name) {
                    include_directory = entity;
                } else if (entity.name === source_directory_name) {
                    source_directory = entity;
                }
            }
        }

        const /* string_t[] */ include_file_names = include_directory ?
            await Directory_File_Names(`${directory_path}/${include_directory.name}`, include_directory.name) :
            null;
        const /* string_t[] */ source_file_names = source_directory ?
            await Directory_File_Names(`${directory_path}/${source_directory.name}`, source_directory.name) :
            null;

        return ({
            include_file_names: include_file_names || [``],
            source_file_names: source_file_names || [``],
        });
    } catch (error) {
        Print_Error(`failed to read directory: ${directory_path}`, error);

        return ({
            include_file_names: [``],
            source_file_names: [``],
        });
    }
}

/*
    Generates the CMakeLists.txt file for each library in the project.
*/
/* void_t */ async function Update_Libraries(/* string_t */ repository_path, /* string_t */ library_names)
{
    for (let /* string_t */ library_name of library_names) {
        const { /* string_t[] */ include_file_names, /* string_t[] */ source_file_names } =
            await Include_And_Source_File_Names(`${repository_path}/${library_name}`, `include`, `src`);

        let /* string_t */ data = `# ${library_name}

            cmake_minimum_required(VERSION ${min_cmake_version})

            project(${library_name}
                    LANGUAGES CXX)

            set(THIS_INCLUDE_FILES${include_file_names.map(s => `\n                "${s}"`).join("")})

            set(THIS_SOURCE_FILES${source_file_names.map(s => `\n                "${s}"`).join("")})

            add_library(${library_name} STATIC)
            target_sources(${library_name} PUBLIC \${THIS_INCLUDE_FILES})
            target_sources(${library_name} PRIVATE \${THIS_SOURCE_FILES})

            target_include_directories(${library_name}
                                       PUBLIC "include")

            source_group(TREE "\${CMAKE_CURRENT_SOURCE_DIR}"
                         PREFIX "File Tree"
                         FILES \${THIS_INCLUDE_FILES} \${THIS_SOURCE_FILES})\n`.replace(/^            /gm, "");

        const /* string_t */ data_path = `${repository_path}/${library_name}/${lists_file_name}`;
        try {
            await Write_File(data_path, data);
        } catch (error) {
            Print_Error(`failed to write file: ${data_path}`, error);
        }
    }
}

/*
    Generates the CMakeLists.txt file for each test-suite in the project.
*/
/* void_t */ async function Update_Tests(/* string_t */ tests_path, /* string_t[] */ test_names)
{
    let /* string_t */ data = `# nkr_tests

        cmake_minimum_required(VERSION ${min_cmake_version})

        ${test_names.map(s => `add_subdirectory("${s}")`).join(`\n        `)}\n`.replace(/^        /gm, "");

    const /* string_t */ data_path = `${tests_path}/${lists_file_name}`;
    try {
        await Write_File(data_path, data);
    } catch (error) {
        Print_Error(`failed to write file: ${data_path}`, error);
    }

    for (let /* string_t */ test_name of test_names) {
        const { /* string_t[] */ include_file_names, /* string_t[] */ source_file_names } =
            await Include_And_Source_File_Names(`${tests_path}/${test_name}`, `include`, `src`);

        const /* string_t */ full_test_name = `nkr_test_${test_name}`;
        let /* string_t */ data = `# ${full_test_name}

            cmake_minimum_required(VERSION ${min_cmake_version})

            project(${full_test_name}
                    LANGUAGES CXX)

            set(THIS_INCLUDE_FILES${include_file_names.map(s => `\n                "${s}"`).join("")})

            set(THIS_SOURCE_FILES${source_file_names.map(s => `\n                "${s}"`).join("")})

            add_executable(${full_test_name})
            target_sources(${full_test_name} PUBLIC \${THIS_INCLUDE_FILES})
            target_sources(${full_test_name} PRIVATE \${THIS_SOURCE_FILES})

            target_include_directories(${full_test_name}
                                       PRIVATE "\${NKR_NKR_INCLUDE_DIR}"
                                       PRIVATE "\${NKR_DOCTEST_INCLUDE_DIR}"
                                       PRIVATE "include")

            target_link_libraries(${full_test_name}
                                  PRIVATE nkr
                                  PRIVATE doctest)

            source_group(TREE "\${CMAKE_CURRENT_SOURCE_DIR}"
                         PREFIX "File Tree"
                         FILES \${THIS_INCLUDE_FILES} \${THIS_SOURCE_FILES})\n`.replace(/^            /gm, "");

        const /* string_t */ data_path = `${tests_path}/${test_name}/${lists_file_name}`;
        try {
            await Write_File(data_path, data);
        } catch (error) {
            Print_Error(`failed to write file: ${data_path}`, error);
        }
    }
}

(/* void_t */ async function Main()
{
    const /* string_t[] */ args = process.argv.slice(2);

    if (args.includes(`-h`) || args.includes(`--help`) || args.length === 0) {
        console.log(help_message);
    } else {
        const /* string_t */ repository_path = path.resolve(args[0]);
        const /* string_t */ tests_path = `${repository_path}/nkr_tests`;

        try {
            const /* fs.Dirent[] */ test_entities = await Read_Directory(tests_path);
            let /* string_t[] */ test_names = [];
            for (let /* fs.Dirent */ test_entity of test_entities) {
                if (test_entity.isDirectory()) {
                    test_names.push(test_entity.name);
                }
            }

            await Update_Libraries(repository_path, [`nkr`, `doctest`]);
            await Update_Tests(`${repository_path}/nkr_tests`, test_names);
        } catch (error) {
            Print_Error(`failed to read directory: ${tests_path}`, error);
        }
    }
})();
