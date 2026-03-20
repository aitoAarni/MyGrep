# 1. Define the minimum CMake version required. 
# Ubuntu 22.04+ usually has 3.22 or higher.
cmake_minimum_required(VERSION 3.20)

# 2. Name your project and specify the language (CXX means C++)
project(MyGrep CXX)

# 3. Force the compiler to use modern C++20. 
# This replaces the need to manually pass "-std=c++20" to g++.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disables compiler-specific extensions to keep code portable

# 4. Tell CMake to create an executable named 'mygrep' 
# using the source code found in 'src/main.cpp'
add_executable(mygrep src/main.cpp src/search_file.cpp src/parse_args.cpp src/handle_output.cpp)

# 5. (Optional but recommended) Turn on strict compiler warnings.
# This is the CMake equivalent of "-Wall -Wextra -Wpedantic"
target_compile_options(mygrep PRIVATE -Wall -Wextra -Wpedantic)