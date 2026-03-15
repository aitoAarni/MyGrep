#include "search_file.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

// fs::recursive_directory_iterator
// fs::directory_entry.is_directory

namespace fs = std::filesystem;

std::vector<std::string> search_file(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "File '" << "'  failed to open\n";
    }
    std::string line{};
    std::cout << "helloo in search_file: " << filename << "\n";
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
    

    std::vector<std::string> result {};
    return result;
}