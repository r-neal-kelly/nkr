/*
    Copyright 2022 r-neal-kelly
*/

`use strict`;

import * as child_process from "child_process";
import * as fs from "fs";

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

/* string_t */ async function Execute_Child_Process(/* string_t */ command, /* object_t */ options)
{
    return new Promise(function (/* function_t */ Resolve, /* function_t */ Reject) {
        child_process.exec(command, options, function (error, stdout, stderr) {
            if (error) {
                Reject(error);
            } else {
                Resolve(stdout);
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

export {
    Read_Directory,
    Read_File,
    Write_File,
    Execute_Child_Process,
    Print_Error,
}
