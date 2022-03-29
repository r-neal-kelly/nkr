param(
    [string]$arch = "x64",
    [string]$mode = "Debug",
    [boolean]$gen_tests = $false
)

if ($gen_tests) {
    $Env:NKR_GENERATE_TESTS = $true
}

node "./tools/update_cmake_lists/update_cmake_lists" "./"

$path = Join-Path (Resolve-Path .) "build/$arch/$mode"

cmake -B "$path" -A "$arch"
cmake --build "$path" --config "$mode" --parallel

Write-Host
Write-Host "Generated and built project at $path"

Write-Host
Write-Host press any key to continue...
Write-Host
Read-Host
