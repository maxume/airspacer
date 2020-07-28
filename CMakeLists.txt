cmake_minimum_required(VERSION 3.5.1)

project(airspacer VERSION 0.0.1)

# Be nice to visual studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Be nice and export compile commands by default, this is handy for clang-tidy
# and for other tools.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-std=c++17)

find_package (Boost 1.68 REQUIRED COMPONENTS regex)

include_directories(3rdparty/catch)
include_directories(3rdparty/trompeloeil)
include_directories(include)

add_subdirectory(doc)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(app)

