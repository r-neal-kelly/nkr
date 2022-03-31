param(
    [switch]$help,
    [string]$arch = "64",
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
    Write-Host "    -arch: The target architecture: '64' or '32'."
    Write-Host "    -mode: The target mode, e.g. 'Debug', 'Release'. If not provided, will skip compiling."
    Write-Host "    -test: Will build test suites and compile them if mode exists."
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
        
                if ($Is_Windows) {
                    $Env:nkr_IS_WINDOWS = $true
    
                    if ("$arch" -eq "32") {
                        cmake -B "$path" -A "Win32"
                    } else {
                        cmake -B "$path" -A "x64"
                    }
                } elseif ($Is_Linux) {
                    $Env:nkr_IS_LINUX = $true
    
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
