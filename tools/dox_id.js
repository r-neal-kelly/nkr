"use strict";

const child_process = require("child_process");

process.env.ComSpec = "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe";

child_process.exec("uuid", async function (error, stdout, stderr) {
    const uuid = "_" + stdout.replace(/-/g, "_").replace(/[\n\r]/g, "");
    child_process.spawn("Write-Output", [`"${uuid}"`, "|", "Set-Clipboard"], { shell: true });
});
