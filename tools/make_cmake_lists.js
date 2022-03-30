/*
    Copyright 2022 r-neal-kelly
*/

`use strict`;

const /* object_t */ fs = require(`fs`);
const /* object_t */ path = require(`path`);

const /* string_t */ lists_file_name = `CMakeLists.txt`;
const /* string_t */ min_cmake_version = `3.21`;
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

/* string_t[] */ async function Read_Directory(directory_path)
{
    return new Promise(function (/* function_t */ Resolve, /* function_t */ Reject)
    {
        fs.readdir(directory_path, { withFileTypes: true }, function (/* error_t */ error, /* string_t[] */ files)
        {
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
    return new Promise(function (/* function_t */ Resolve, /* function_t */ Reject)
    {
        fs.readFile(path_to_file, `utf8`, function (/* error_t */ error, /* string_t */ file_text)
        {
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
    return new Promise(function (/* function_t */ Resolve, /* function_t */ Reject)
    {
        fs.writeFile(path_to_file, file_text, `utf8`, function (/* error_t */ error)
        {
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
    Generates the primary CMakeLists.txt file for the project.
*/
/* void_t */ async function Update_Top(/* string_t */ repository_path, /* string_t[] */ test_names)
{
    let /* string_t */ data = `cmake_minimum_required(VERSION ${min_cmake_version})

        project(nkr
                LANGUAGES CXX)

        include(CheckCXXCompilerFlag)

        # Commonly needed directories
        set(NKR_BUILD_DIR "\${CMAKE_BINARY_DIR}")
        set(NKR_BUILD_LIB_DIR "\${NKR_BUILD_DIR}/lib")
        set(NKR_BUILD_BIN_DIR "\${NKR_BUILD_DIR}/bin")

        set(NKR_DIR "\${CMAKE_SOURCE_DIR}")
        set(NKR_NKR_DIR "\${NKR_DIR}/nkr")
        set(NKR_NKR_INCLUDE_DIR "\${NKR_NKR_DIR}/include")
        set(NKR_DOCTEST_DIR "\${NKR_DIR}/doctest")
        set(NKR_DOCTEST_INCLUDE_DIR "\${NKR_DOCTEST_DIR}/include")

        # All libraries go in one folder and all executables in another.
        # This applies to all libraries and executables in this project.
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "\${NKR_BUILD_LIB_DIR}")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "\${NKR_BUILD_BIN_DIR}")

        set(CMAKE_CXX_STANDARD 20)

        set_property(GLOBAL PROPERTY USE_FOLDERS ON)

        # We need to check if certain flags are available and set them if so
        unset(NKR_COMPILER_HAS_STD_CPP_LATEST CACHE)
        check_cxx_compiler_flag("/std:c++latest" NKR_COMPILER_HAS_STD_CPP_LATEST)
        if (NKR_COMPILER_HAS_STD_CPP_LATEST)
            add_compile_options("/std:c++latest")
        endif()

        unset(NKR_COMPILER_HAS_STD_C17 CACHE)
        check_cxx_compiler_flag("/std:c17" NKR_COMPILER_HAS_STD_C17)
        if (NKR_COMPILER_HAS_STD_C17)
            add_compile_options("/std:c17")
        endif()

        unset(NKR_COMPILER_HAS_W3 CACHE)
        check_cxx_compiler_flag("/W3" NKR_COMPILER_HAS_W3)
        if (NKR_COMPILER_HAS_W3)
            add_compile_options("/W3")
        endif()

        unset(NKR_COMPILER_HAS_VOLATILE_ISO CACHE)
        check_cxx_compiler_flag("/volatile:iso" NKR_COMPILER_HAS_VOLATILE_ISO)
        if (NKR_COMPILER_HAS_VOLATILE_ISO)
            add_compile_options("/volatile:iso")
        endif()

        unset(NKR_COMPILER_HAS_BIGOBJ CACHE)
        check_cxx_compiler_flag("/bigobj" NKR_COMPILER_HAS_BIGOBJ)
        if (NKR_COMPILER_HAS_BIGOBJ)
            add_compile_options("/bigobj")
        endif()

        add_subdirectory("nkr")

        if (DEFINED ENV{NKR_GENERATE_TESTS})
            add_subdirectory("doctest")
            ${test_names.map(s => `add_subdirectory("nkr_tests/${s}")`).join(`\n            `)}
        endif()

        # Just some helpful console ouput
        if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
            message("---- Configuring for MSVC...")
        endif()
        message("---- Generating configuration from source at: \${NKR_DIR}")
        message("---- Archives will be available at: \${NKR_BUILD_LIB_DIR}")
        message("---- Executables will be available at: \${NKR_BUILD_BIN_DIR}")\n`.replace(/^        /gm, "");

    const /* string_t */ data_path = `${repository_path}/${lists_file_name}`;
    try {
        await Write_File(data_path, data);
    } catch (error) {
        Print_Error(`failed to write file: ${data_path}`, error);
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
            await Update_Libraries(repository_path, [`nkr`, `doctest`]);
            await Update_Tests(`${repository_path}/nkr_tests`, test_names);
        } catch (error) {
            Print_Error(`failed to read directory: ${tests_path}`, error);
        }
    }
})();
