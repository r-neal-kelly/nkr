/*
    Copyright 2022 r-neal-kelly
*/

`use strict`;

const /* object_t */ fs     = require(`fs`);
const /* object_t */ path   = require(`path`);

const /* string_t */ help_message = `
Info:

    Will create a "CMakeLists_Sources.cmake" file for all "CMakeLists.txt" files.
    The new file will contain a target_sources call to add each include and source file.
    "CMakeLists_Sources.cmake" needs to be manually include()'d in the "CMakeLists.txt" file.

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

/* void_t */ async function Update_Directory(/* string_t */ directory_path, directory_name)
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
                if (entity.name === "CMakeLists.txt") {
                    cmakelists_file = entity;
                }
            }
        }

        if (cmakelists_file) {
            const /* string_t[] */ include_file_names =
                include_directory ? await Directory_File_Names(`${directory_path}/${include_directory.name}`, include_directory.name) : null;
            const /* string_t[] */ source_file_names =
                source_directory ? await Directory_File_Names(`${directory_path}/${source_directory.name}`, source_directory.name) : null;

            let /* string_t */ cmakelists_sources_string = `# ${path.normalize(directory_path)}\n\n`;

            cmakelists_sources_string += `function(add_target_includes target_name)\n`;
            if (include_file_names) {
                cmakelists_sources_string +=
                    `    target_sources(\${target_name} PUBLIC\n                   ` +
                    `${include_file_names.map(s => `"${s}"`).join(`\n                   `)})\n`;
            }
            cmakelists_sources_string += `endfunction()\n\n`;

            cmakelists_sources_string += `function(add_target_sources target_name)\n`;
            if (source_file_names) {
                cmakelists_sources_string +=
                    `    target_sources(\${target_name} PRIVATE\n                   ` +
                    `${source_file_names.map(s => `"${s}"`).join(`\n                   `)})\n`;
            }
            cmakelists_sources_string += `endfunction()\n`;

            const /* string_t */ cmakelists_sources_path = `${directory_path}/CMakeLists_Sources.cmake`;
            try {
                await Write_File(cmakelists_sources_path, cmakelists_sources_string);
            } catch(error) {
                Print_Error(`failed to write file: ${cmakelists_sources_path}`, error);
            }
        }
    } catch(error) {
        Print_Error(`failed to read directory: ${directory_path}`, error);
    }
}

(/* void_t */ async function Main()
{
    const /* string_t[] */ arguments = process.argv.slice(2);

    if (arguments[0] == `-h` || arguments[0] == `--help` || arguments[0] == null) {
        console.log(help_message);
    } else {
        const /* string_t */ repository_path = path.resolve(arguments[0]);
        const /* string_t[] */ directory_names = [`doctest`, `nkr`, `nkr_tests`];

        for (let /* string_t */ directory_name of directory_names) {
            await Update_Directory(`${repository_path}/${directory_name}`, directory_name);
        }
    }
})();
