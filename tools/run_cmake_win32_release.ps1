$arch = "Win32"
$mode = "Release"

cd ../

$path = Join-Path (Resolve-Path .) "build/$arch/$mode"

cmake -B "$path" -A "$arch"
cmake --build "$path" --config "$mode"

Write-Host
Write-Host "Generated and built project at $path"

Write-Host
Write-Host press any key to continue...
Write-Host
Read-Host
