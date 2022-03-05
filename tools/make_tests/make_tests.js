`use strict`;

const /* object_t */ fs                 = require(`fs`);

const /* string_t */ nkr_dir            = `../..`;
const /* string_t */ nkr_tests_dir      = `${nkr_dir}/nkr_tests`;
const /* string_t */ tools_dir          = `${nkr_dir}/tools`;
const /* string_t */ test_file_prefix   = `run_tests`;

/* string_t[] */ async function Test_Suite_Names()
{
    return new Promise(function (/* function_t */ Resolve, /* function_t */ Reject) {
        fs.readdir(nkr_tests_dir, function (/* error_t */ error, /* string_t[] */ files) {
            if (error) {
                Reject(error);
            } else {
                Resolve(files);
            }
        });
    });
}

/* void_t */ async function Make_Test_File(/* string_t */ file_name, /* string_t */ data)
{
    return new Promise(function (/* function_t */ Resolve, /* function_t */ Reject) {
        fs.writeFile(`${tools_dir}/${file_name}`, data, function (/* error_t */ error) {
            if (error) {
                Reject(error);
            } else {
                Resolve();
            }
        });
    });
}

/* void_t */ async function PS1(/* string_t[] */ test_suite_names) /* no_throw */
{
    /* string_t */ function File_Text(/* string_t */ target_dir, /* string_t[] */ test_suite_names) /* no_throw */
    {
        return test_suite_names.map(function (/* string_t */ test_suite_name) {
            return `` +
                `Write-Host Testing ${target_dir}/${test_suite_name}...` + `\r\n` +
                `../${target_dir}/nkr_test_${test_suite_name}.exe` + `\r\n` +
                `Write-Host` + `\r\n`;
        }).reduce(function (/* string_t */ previous_value, /* string_t */ value) {
            return previous_value + value;
        });
    }

    const /* string_t */ x64_debug_text = File_Text(`x64/Debug`, test_suite_names);
    const /* string_t */ x64_release_text = File_Text(`x64/Release`, test_suite_names);
    const /* string_t */ win32_debug_text = File_Text(`Win32/Debug`, test_suite_names);
    const /* string_t */ win32_release_text = File_Text(`Win32/Release`, test_suite_names);

    const /* string_t */ end_file_text = `` +
        `Write-Host press any key to continue...` + `\r\n` +
        `Write-Host` + `\r\n` +
        `Read-Host` + `\r\n`;

    try {
        await Promise.all([
            Make_Test_File(`${test_file_prefix}_x64_debug.ps1`, x64_debug_text + end_file_text),
            Make_Test_File(`${test_file_prefix}_x64_release.ps1`, x64_release_text + end_file_text),
            Make_Test_File(`${test_file_prefix}_win32_debug.ps1`, win32_debug_text + end_file_text),
            Make_Test_File(`${test_file_prefix}_win32_release.ps1`, win32_release_text + end_file_text),
        ]);
        try {
            await Make_Test_File(`${test_file_prefix}_all.ps1`,
                x64_debug_text + `\r\n` +
                x64_release_text + `\r\n` +
                win32_debug_text + `\r\n` +
                win32_release_text + `\r\n` +
                end_file_text
            );
        } catch (error) {
            console.log(`Failed to make the file with all tests for all targets`);
        }
    } catch (error) {
        console.log(`Failed to make individual target files:`);
        console.log(error);
    }
}

(/* void_t */ async function Main()
{
    try {
        const /* string_t[] */ test_suite_names = await Test_Suite_Names();

        if (process.platform == `win32`) {
            PS1(test_suite_names);
        } else {
            console.log(`Currently unsupported operating system.`);
        }
    } catch(error) {
        console.log(`Failed to read nkr_tests directory:`);
        console.log(error);
    }
})();
