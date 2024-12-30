@echo off
REM Add the submodule
git submodule add https://github.com/sblantipodi/platformio_version_increment.git platformio_version_increment

REM Initialize the submodule
git submodule init

REM Update the submodule recursively
git submodule update --init --recursive

REM Print a message indicating the script has completed
echo Submodule added, initialized, and updated successfully.
pause