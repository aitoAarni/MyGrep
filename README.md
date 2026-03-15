# 1. When CMakeLists.txt is changed run
cmake -S . -B build

# 2. Build the code
cmake --build build

# 3. Run main.cpp with args!
./build/mygrep "iostream" "./src/main.cpp"