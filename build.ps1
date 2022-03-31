param(
    [switch]$help,
    [string]$arch = "",
    [string]$mode = "",
    [switch]$test
)

if ($help.IsPresent) {
    Write-Host
    Write-Host "Info:"
    Write-Host "    Uses CMake to generate build files and then subsequently compiles the library."
    Write-Host "    Requires CMake and Node.js to be installed and available in the PATH."
    Write-Host "    Places all configurations in the './build' directory."
    Write-Host
    Write-Host "Parameters:"
    Write-Host "    -help: Brings up this help message."
    Write-Host "    -arch: The target architecture, e.g. 'x64', 'Win32'."
    Write-Host "    -mode: The target mode, e.g. 'Debug', 'Release'. If not provided, will skip compiling."
    Write-Host "    -test: Will build and compile the test suites."
    Write-Host
} else {
    if ((Get-Command "node" -ErrorAction SilentlyContinue) -eq $null) {
        Write-Host
        Write-Host "This program requires Node.js to be installed and available in the PATH."
        Write-Host "If you prefer, you can simply use CMake to manually generate and build the library."
        Write-Host
    } elseif ((Get-Command "cmake" -ErrorAction SilentlyContinue) -eq $null) {
        Write-Host
        Write-Host "This program requires CMake to be installed and available in the PATH."
        Write-Host
    } else {
        if ($test.IsPresent) {
            $Env:NKR_GENERATE_TESTS = $true
        }

        node "./tools/make_cmake_lists" "./"

        $path = Join-Path (Resolve-Path .) "build/$arch"

        if (-not "$arch" -eq "") {
            cmake -B "$path" -A "$arch"
        } else {
            cmake -B "$path"
        }
        
        if (-not "$mode" -eq "") {
            cmake --build "$path" --config "$mode" --parallel
            
            Write-Host
            Write-Host "Generated and compiled project at $path"
        } else {
            Write-Host
            Write-Host "Generated project at $path"
        }
        
        if ($test.IsPresent) {
            node "./tools/make_run_tests" "$path"
        }
        
        Write-Host
        Write-Host press any key to continue...
        Write-Host
        Read-Host
    }
}
