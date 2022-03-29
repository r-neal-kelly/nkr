/*
    Copyright 2022 r-neal-kelly
*/

`use strict`;

const /* object_t */ fs     = require(`fs`);
const /* object_t */ path   = require(`path`);

const /* string_t */ lists_file_name = `CMakeLists.txt`;
const /* string_t */ funcs_file_name = `CMakeLists_Funcs.cmake`;
const /* string_t */ help_message = `
Info:

    Will create a "${funcs_file_name}" file for all "${lists_file_name}" files.
    The new file will contain a target_sources call to add each include and source file.
    "${funcs_file_name}" needs to be manually include()'d in the "${lists_file_name}" file.

Parameter #1:

    relative or absolute path, e.g. "../../":
        Must be the top folder in the nkr repository.
    
    "-h" or "--help" or (none):
        Displays this message in the terminal.
`;

/* string_t[] */ async function Read_Directory(directory_path)
{
    return new Promise(function (/* function_t */ Resolve, /* function_t */ Reject) {
        fs.readdir(directory_path, { withFileTypes: true }, function (/* error_t */ error, /* string_t[] */ files) {
            if (error) {
                Reject(error);
            } else {
                Resolve(files);
            }
        });
    });
}

/* string_t */ async function Read_File(/* string_t */ path_to_file)
{
    return new Promise(function (/* function_t */ Resolve, /* function_t */ Reject) {
        fs.readFile(path_to_file, `utf8`, function (/* error_t */ error, /* string_t */ file_text) {
            if (error) {
                Reject(error);
            } else {
                Resolve(file_text);
            }
        });
    });
}

/* void_t */ async function Write_File(/* string_t */ path_to_file, /* string_t */ file_text)
{
    return new Promise(function (/* function_t */ Resolve, /* function_t */ Reject) {
        fs.writeFile(path_to_file, file_text, `utf8`, function (/* error_t */ error) {
            if (error) {
                Reject(error);
            } else {
                Resolve();
            }
        });
    });
}

/* void_t */ function Print_Error(/* string_t */ message, /* error_t */ error)
{
    console.log(`\n`);
    console.log(message);
    console.log(error);
    console.log(`\n`);
}

/*
    Recursively gets a list of all file names resolved by the passed in path. Excludes any directory itself.
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
        } catch(error) {
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
    Creates the funcs cmake file for every lists cmake file, which contains functions that can get
    include and source file names.
*/
/* void_t */ async function Update_Directory(/* string_t */ directory_path, /* string_t */ directory_name)
{
    try {
        const /* fs.Dirent[] */ entities = await Read_Directory(directory_path);
        let /* fs.Dirent */ include_directory = null;
        let /* fs.Dirent */ source_directory = null;
        let /* fs.Dirent */ cmakelists_file = null;

        for (let /* fs.Dirent */ entity of entities) {
            if (entity.isDirectory()) {
                if (entity.name === `include`) {
                    include_directory = entity;
                } else if (entity.name === `src`) {
                    source_directory = entity;
                } else {
                    await Update_Directory(`${directory_path}/${entity.name}`, entity.name);
                }
            } else if (entity.isFile()) {
                if (entity.name === lists_file_name) {
                    cmakelists_file = entity;
                }
            }
        }

        if (cmakelists_file) {
            const /* string_t[] */ include_file_names =
                include_directory ? await Directory_File_Names(`${directory_path}/${include_directory.name}`, include_directory.name) : null;
            const /* string_t[] */ source_file_names =
                source_directory ? await Directory_File_Names(`${directory_path}/${source_directory.name}`, source_directory.name) : null;

            let /* string_t */ data = `# ${directory_name}\n\n`;

            data += `function(get_include_files RESULT)\n`;
            data += `    set(\${RESULT}\n`;
            data += `        "${lists_file_name}"\n`;
            data += `        "${funcs_file_name}"\n`;
            if (include_file_names) {
                data += `        ${include_file_names.map(s => `"${s}"`).join(`\n        `)}\n`;
            }
            data += `        PARENT_SCOPE)\n`;
            data += `endfunction()\n\n`;

            data += `function(get_source_files RESULT)\n`;
            data += `    set(\${RESULT}\n`;
            if (source_file_names) {
                data += `        ${source_file_names.map(s => `"${s}"`).join(`\n        `)}\n`;
            } else {
                data += `        ""\n`;
            }
            data += `        PARENT_SCOPE)\n`;
            data += `endfunction()\n\n`;

            data += `function(get_all_files RESULT)\n`;
            data += `    get_include_files(THIS_INCLUDE_FILES)\n`;
            data += `    get_source_files(THIS_SOURCE_FILES)\n`;
            data += `    set(\${RESULT} \${THIS_INCLUDE_FILES} \${THIS_SOURCE_FILES} PARENT_SCOPE)\n`;
            data += `endfunction()\n`;

            const /* string_t */ data_path = `${directory_path}/${funcs_file_name}`;
            try {
                await Write_File(data_path, data);
            } catch(error) {
                Print_Error(`failed to write file: ${data_path}`, error);
            }
        }
    } catch(error) {
        Print_Error(`failed to read directory: ${directory_path}`, error);
    }
}

/*
    Adds a funcs cmake file to the top repository and updates all library directories.
*/
/* void_t */ async function Update_Top(/* string_t */ repository_path, /* string_t[] */ test_names)
{
    let /* string_t */ data = '';
    data += `# repository\n\n`;

    data += `function(get_test_directories RESULT)\n`;
    data += `    set(\${RESULT}\n`;
    data += `        "doctest"\n`;
    data += `        ${test_names.map(s => `"nkr_tests/${s}"`).join(`\n        `)}\n`;
    data += `        PARENT_SCOPE)\n`;
    data += `endfunction()\n\n`;

    const /* string_t */ data_path = `${repository_path}/${funcs_file_name}`;
    try {
        await Write_File(data_path, data);
    } catch(error) {
        Print_Error(`failed to write file: ${data_path}`, error);
    }

    for (let /* string_t */ directory_name of [`nkr`, `doctest`]) {
        await Update_Directory(`${repository_path}/${directory_name}`, directory_name);
    }
}

/*
    Creates the lists cmake file for all test suites and updates each test directory.
*/
/* void_t */ async function Update_Tests(/* string_t */ tests_path, /* string_t[] */ test_names)
{
    for (let /* string_t */ test_name of test_names) {
        const /* string_t */ full_test_name = `nkr_test_${test_name}`;
        let /* string_t */ data = ``;

        data += `# ${full_test_name}\n\n`;

        data += `cmake_minimum_required(VERSION 3.23)\n\n`;

        data += `project(${full_test_name}\n`;
        data += `        LANGUAGES CXX)\n\n`;

        data += `include("CMakeLists_Funcs.cmake")\n\n`;

        data += `get_include_files(THIS_INCLUDE_FILES)\n`;
        data += `get_source_files(THIS_SOURCE_FILES)\n\n`;

        data += `add_executable(${full_test_name})\n`;
        data += `target_sources(${full_test_name} PUBLIC \${THIS_INCLUDE_FILES})\n`;
        data += `target_sources(${full_test_name} PRIVATE \${THIS_SOURCE_FILES})\n\n`;
        
        data += `target_include_directories(${full_test_name}\n`;
        data += `                           PRIVATE "\${NKR_NKR_INCLUDE_DIR}"\n`;
        data += `                           PRIVATE "\${NKR_DOCTEST_INCLUDE_DIR}"\n`;
        data += `                           PRIVATE "include")\n\n`;

        data += `target_link_libraries(${full_test_name}\n`;
        data += `                      PRIVATE nkr\n`;
        data += `                      PRIVATE doctest)\n\n`;

        data += `source_group(TREE "\${CMAKE_CURRENT_SOURCE_DIR}"\n`;
        data += `             PREFIX "File Tree"\n`;
        data += `             FILES \${THIS_INCLUDE_FILES} \${THIS_SOURCE_FILES})\n`;

        const /* string_t */ data_path = `${tests_path}/${test_name}/${lists_file_name}`;
        try {
            await Write_File(data_path, data);
            await Update_Directory(`${tests_path}/${test_name}`, test_name);
        } catch(error) {
            Print_Error(`failed to write file: ${data_path}`, error);
        }
    }
}

(/* void_t */ async function Main()
{
    const /* string_t[] */ arguments = process.argv.slice(2);

    if (arguments[0] == `-h` || arguments[0] == `--help` || arguments[0] == null) {
        console.log(help_message);
    } else {
        const /* string_t */ repository_path = path.resolve(arguments[0]);
        const /* string_t */ tests_path = `${repository_path}/nkr_tests`;

        try {
            const /* fs.Dirent[] */ test_entities = await Read_Directory(tests_path);
            let /* string_t[] */ test_names = [];
            for (let /* fs.Dirent */ test_entity of test_entities) {
                if (test_entity.isDirectory()) {
                    test_names.push(test_entity.name);
                }
            }

            await Update_Top(repository_path, test_names);
            await Update_Tests(`${repository_path}/nkr_tests`, test_names);
        } catch(error) {
            Print_Error(`failed to read directory: ${tests_path}`, error);
        }
    }
})();
