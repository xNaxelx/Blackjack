# Blackjack

Single player game on SDL2, with runtime skin replacement system.
Also used STL, Boost


https://user-images.githubusercontent.com/46362288/235438834-a797b15f-63ca-44e7-8d09-55a41ee18956.mp4

# Project compilation
## Requirements
 - [CMake](https://cmake.org/download/)
 - [vcpkg](https://github.com/Microsoft/vcpkg/#quick-start-windows)
## Library installation

Execute commands in vcpkg:
 - `vcpkg install sdl2:x64-windows`
 - `vcpkg install sdl2-image:x64-windows`
 - `vcpkg install sdl2-mixer:x64-windows`
 - `vcpkg install sdl2-ttf:x64-windows`
 - `vcpkg install boost-filesystem:x64-windows`
 - `vcpkg install boost-function:x64-windows`
 - `vcpkg install boost-functional:x64-windows`
 - `vcpkg install boost-bind:x64-windows`
 - `vcpkg integrate install`

## Generate project files

1. In CMakeLists.txt on the first line change the path to vcpkg
2. Open cmake-gui.exe
3. Specify the path to the folder with the project and the folder where the assembly will be made
 ![image](https://github.com/xNaxelx/Blackjack/assets/46362288/2ec5a995-7afc-4457-aa89-bf9a9f0fdd0e)
4. Press `Configure` and after the end `Generate`
