set CMAKE_EXPORT_COMPILE_COMMANDS=TRUE
CALL "C:\Program Files\Microsoft Visual Studio\2022\Community\\VC\Auxiliary\Build\VCVARSALL.BAT" amd64
@if errorlevel 1 (
    @echo The VCVARSALL command returned an error of %errorlevel% 1>&2
    @exit /B 1
)

C:\PROGRA~1\MATLAB\R2023a\bin\win64\cmake\bin\cmake.exe -S . -B build -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release  -DCMAKE_PLATFORM_INFO_INITIALIZED:INTERNAL=1 --no-warn-unused-cli -DCMAKE_INSTALL_PREFIX=".."
@if errorlevel 1 (
    @echo The cmake command returned an error of %errorlevel% 1>&2
    @exit /B 1
)

C:\PROGRA~1\MATLAB\R2023a\bin\win64\cmake\bin\cmake.exe --build build
@if errorlevel 1 (
    @echo The cmake command returned an error of %errorlevel% 1>&2
    @exit /B 1
)

C:\PROGRA~1\MATLAB\R2023a\bin\win64\cmake\bin\cmake.exe --install build --prefix ..
@if errorlevel 1 (
    @echo The cmake command returned an error of %errorlevel% 1>&2
    @exit /B 1
)

