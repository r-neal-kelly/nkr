$arch = "x64"
$mode = "Release"

cd ../

node "./tools/update_cmake_lists/update_cmake_lists" "./"

$path = Join-Path (Resolve-Path .) "build/$arch/$mode"

cmake -B "$path" -A "$arch"
cmake --build "$path" --config "$mode"

Write-Host
Write-Host "Generated and built project at $path"

Write-Host
Write-Host press any key to continue...
Write-Host
Read-Host
