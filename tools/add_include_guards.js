/*
    Copyright 2022 r-neal-kelly
*/

`use strict`;

import * as path from "path";

import {
    Read_Directory,
    Read_File,
    Write_File,
    Print_Error,
} from "./common.js"

import {
    Can_Create_UUID,
    Create_UUID,
    UUID_Regex,
} from "./create_uuid.js"

const /* string_t */ help_message = `
Info:

    Updates all instances of '#pragma once' and all include guards without a valid uuid.

Parameter #1:

    relative or absolute path, e.g. "./":
        Must be the top folder of the nkr repository.
    
    "-h" or "--help" or (none):
        Displays this message in the terminal.
`;

/*
    Will remove all instances of #pragma once and instead add a valid include guard if its missing.
    A valid include guard must have a specifically formatted universally unique id.
    Does not remove existing include guards.
*/
/* void_t */ async function Add_Include_Guards(/* string_t[] */ directory_paths)
{
    /* void_t */ async function Accumulate(/* string_t */ directory_path, /* string_t[] */ header_file_paths)
    {
        try {
            const /* fs.Dirent[] */ entities = await Read_Directory(directory_path);
            for (const entity of entities) {
                if (entity.isDirectory()) {
                    await Accumulate(`${directory_path}/${entity.name}`, header_file_paths);
                } else if (entity.isFile()) {
                    if (/\.h$/.test(entity.name)) {
                        header_file_paths.push(`${directory_path}/${entity.name}`);
                    }
                }
            }
        } catch(error) {
            Print_Error(`failed to read directory: ${directory_path}`, error);
        }
    }

    let /* string_t[] */ header_file_paths = [];
    for (const /* string_t */ directory_path of directory_paths) {
        await Accumulate(directory_path, header_file_paths);
    }

    const /* string_t */ guard_prefix = `nkr_INCLUDE_GUARD`;
    const /* regex_t */ conformant_guard_regex = RegExp(` *#ifndef *(${guard_prefix}${UUID_Regex()}) *(\\n|\\r\\n) *#define \\1.*#endif *(\\n|\\r\\n)*$`, `s`);
    const /* regex_t */ pragma_once_regex = / *#pragma *once *(\n|\r\n)*/g;
    const /* regex_t */ top_comment_regex = /^ *\/\*.*?\*\//s;

    for (const /* string_t */ header_file_path of header_file_paths) {
        try {
            let /* string_t */ header_file_data = await Read_File(header_file_path);
            let /* bool_t */ should_write_data = false;

            if (pragma_once_regex.test(header_file_data)) {
                should_write_data = true;

                header_file_data = header_file_data.replace(pragma_once_regex, ``);
            }

            if (!conformant_guard_regex.test(header_file_data)) {
                should_write_data = true;

                try {
                    const /* string_t */ guard_uuid = `${guard_prefix}${await Create_UUID()}`;
                    let /* match_t */ top_comment_match = header_file_data.match(top_comment_regex);
                    if (top_comment_match) {
                        header_file_data =
                            top_comment_match[0] + `\n\n` +
                            `#ifndef ${guard_uuid}\n` +
                            `#define ${guard_uuid}` +
                            header_file_data.substring(top_comment_match[0].length) +
                            `\n#endif\n`;
                    } else {
                        header_file_data =
                            `#ifndef ${guard_uuid}\n` +
                            `#define ${guard_uuid}\n\n` +
                            header_file_data +
                            `\n#endif\n`;
                    }
                } catch (error) {
                    Print_Error(`failed to create a uuid for ${header_file_path}. Skipping file.`, error);
                    should_write_data = false;
                }                
            }

            if (should_write_data) {
                try {
                    await Write_File(header_file_path, header_file_data);
                    console.log(`added an include guard for ${header_file_path}`);
                } catch (error) {
                    Print_Error(`failed to write file: ${header_file_path}`, error);
                }
            }
        } catch (error) {
            Print_Error(`failed to read file: ${header_file_path}`, error);
        }
    }
}

(/* void_t */ async function Main()
{
    const /* string_t[] */ args = process.argv.slice(2);

    if (args.includes(`-h`) || args.includes(`--help`) || args.length === 0) {
        console.log(help_message);
    } else {
        if (await Can_Create_UUID()) {
            const /* string_t */ repository_path = path.resolve(args[0]);

            await Add_Include_Guards([
                `${repository_path}/nkr`,
                `${repository_path}/nkr_tests`
            ]);
        } else {
            Print_Error("cannot create uuids to update include guards.", null);
        }
    }
})();
