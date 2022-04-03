param(
    [switch]$help,
    [string]$arch = "64",
    [string]$mode = "Debug",
    [switch]$test,
    [switch]$make,
    [switch]$exec
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
    Write-Host "    -arch: The target architecture: '32' or '64'. Default: '64'."
    Write-Host "    -mode: The target mode: e.g. 'Debug', 'Release'. Default: 'Debug'."
    Write-Host "    -test: Will generate test suites."
    Write-Host "    -make: Will compile the generated build files."
    Write-Host "    -exec: Will execute all compiled executable tests."
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
        $Is_Windows = $IsWindows -or ([System.Environment]::OSVersion.Platform -eq "Win32NT")
        $Is_Linux = $IsLinux

        if ($Is_Windows -or $Is_Linux) {
            if ("$arch" -eq "32" -or "$arch" -eq "64") {
                if ("$arch" -eq "32") {
                    $Env:nkr_IS_32_BIT = $true
                } else {
                    $Env:nkr_IS_64_BIT = $true
                }
    
                if ($test.IsPresent) {
                    $Env:nkr_DO_GENERATE_TESTS = $true
                }
        
                $path = Join-Path (Resolve-Path .) "build/$arch"
    
                node "./tools/make_cmake_lists" "./"

                node "./tools/add_include_guards" "./"
        
                if ($Is_Windows) {
                    $Env:nkr_IS_WINDOWS = $true
    
                    if ("$arch" -eq "32") {
                        cmake -B "$path" -A "Win32" -DCMAKE_BUILD_TYPE="$mode"
                    } else {
                        cmake -B "$path" -A "x64" -DCMAKE_BUILD_TYPE="$mode"
                    }
                } elseif ($Is_Linux) {
                    $Env:nkr_IS_LINUX = $true
    
                    cmake -B "$path" -DCMAKE_BUILD_TYPE="$mode"
                }
                
                if ($make.IsPresent) {
                    cmake --build "$path" --config "$mode" --parallel
                    
                    Write-Host
                    Write-Host "Generated and compiled project at $path"
                } else {
                    Write-Host
                    Write-Host "Generated project at $path"
                }
                
                if ($test.IsPresent) {
                    node "./tools/make_run_tests" "$path"

                    if ($exec.IsPresent) {
                        Write-Host "Executing tests at $path..."
                        Invoke-Expression "$path/run_tests.ps1"
                    }
                }
                
                Write-Host "Finished."
                Write-Host
            } else {
                Write-Host
                Write-Host "This program requires an 'arch' of 32 or 64 (default is 64)."
                Write-Host
            }
        } else {
            Write-Host
            Write-Host "This program requires Windows or Linux."
            Write-Host
        }
    }
}
