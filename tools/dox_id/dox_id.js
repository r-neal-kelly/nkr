"use strict";

const child_process = require("child_process");

/*tuple_t[boolean_t did_succeed, string_t result]*/ async function Execute_Child_Process(/*string_t*/ command, /*object_t*/ options)
{
    return new Promise(function (Resolve, Reject) {
        child_process.exec(command, options, function (error, stdout, stderr) {
            if (error) {
                Resolve([false, stderr]);
            } else {
                Resolve([true, stdout]);
            }
        });
    });
}

/*void_t*/ async function Write_To_Clipboard(/*string_t*/ string)
{
    return new Promise(function (Resolve, Reject) {
        // We need powershell for the copy to clipboard command.
        // This technique is safe because JavaScript is single threaded.
        // However, the switch back to cmd is necessary because NodeJS doesn't work well with powershell generally.
        // But make sure it's switched back right after making the shell because doing it out of sync may lead to unexpected results.
        process.env.ComSpec = `C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe`;
        shell = child_process.spawn(`Write-Output`, [`"${string}"`, `|`, `Set-Clipboard`], { shell: true });
        process.env.ComSpec = `C:\\Windows\\System32\\cmd.exe`;

        shell.on(`close`, function () {
            Resolve();
        });
    });
}

/*string_t formatted_uuid*/ function Formatted_UUID(/*string_t*/ uuid)
{
    return "_" + uuid.replace(/-/g, "_").replace(/[\n\r]/g, "");
}

(/*void_t*/ async function Main()
{
    const [has_npm, ] = await Execute_Child_Process(`npm -v`);
    if (has_npm) {
        const [has_uuid, uuid_or_error] = await Execute_Child_Process(`uuid`);
        if (has_uuid) {
            await Write_To_Clipboard(Formatted_UUID(uuid_or_error));
        } else {
            const [installed_uuid, installed_uuid_or_error] = await Execute_Child_Process(`npm install -g uuid`);
            if (installed_uuid) {
                const [has_uuid, uuid_or_error] = await Execute_Child_Process(`uuid`);
                if (has_uuid) {
                    await Write_To_Clipboard(Formatted_UUID(uuid_or_error));
                } else {
                    await Write_To_Clipboard(uuid_or_error);
                }
            } else {
                await Write_To_Clipboard(installed_uuid_or_error);
            }
        }
    } else {
        await Write_To_Clipboard("ERROR: You need to install NodeJS.");
    }
})();
