/*
    Copyright 2022 r-neal-kelly
*/

`use strict`;

const /* object_t */ fs = require(`fs`);
const /* object_t */ path = require(`path`);

const /* string_t */ run_tests_prefix = `run_tests`;
const /* string_t */ help_message = `
Info:

    Will create a "${run_tests_prefix}" file that will execute all the test-suites
    in the generated 'bin' folder. Only useful if there are executables in 'bin'.

Parameter #1:

    relative or absolute path, e.g. "../build/x64":
        Must be a path to a folder that contains a 'bin' directory.
    
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

/* void_t */ async function PS1(/* string_t */ build_path, /* string_t*/ bin_path) /* no_throw */
{
    /* void_t */ async function Executable_Paths(/* string_t*/ path, /* string_t[] */ accumulator)
    {
        try {
            const /* fs.Dirent[] */ entities = await Read_Directory(path);
            for (let entity of entities) {
                if (entity.isDirectory()) {
                    await Executable_Paths(`${path}/${entity.name}`, accumulator);
                } else if (entity.isFile()) {
                    if (/\.exe$/.test(entity.name)) {
                        accumulator.push(`${path}/${entity.name}`);
                    }
                }
            }
        } catch (error) {
            Print_Error(`failed to read directory: ${path}`, error);
        }
    }
    /* string_t[] */ let executables = [];
    await Executable_Paths(bin_path, executables);

    const /* string_t */ data = `# Will run all .exe files in bin.

        ${executables.map(s => `Write-Host "Testing ${s}"...\n        ${s}\n        Write-Host\n`).join(``)}
        Write-Host
        Write-Host press any key to continue...
        Write-Host
        Read-Host`.replace(/^        /gm, ``);

    const /* string_t */ data_path = `${build_path}/${run_tests_prefix}.ps1`;
    try {
        await Write_File(data_path, data);
    } catch (error) {
        Print_Error(`failed to write file: ${data_path}`, error);
    }
}

(/* void_t */ async function Main()
{
    const /* string_t[] */ arguments = process.argv.slice(2);

    if (arguments[0] == `-h` || arguments[0] == `--help` || arguments[0] == null) {
        console.log(help_message);
    } else {
        const /* string_t */ build_path = path.resolve(arguments[0]);
        const /* string_t */ bin_path = `${build_path}/bin`;

        if (fs.existsSync(bin_path)) {
            if (process.platform == `win32` || process.platform == `linux`) {
                PS1(build_path, bin_path);
            } else {
                console.log(`Currently unsupported operating system.`);
            }
        } else {
            console.log(`Skipping make_run_tests because ${bin_path} does not exist.`)
        }
    }
})();
