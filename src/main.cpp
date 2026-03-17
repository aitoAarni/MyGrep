#include <iostream>
#include <string_view>
#include <string>
#include "search_file.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <pattern> <directory>\n";
        return 1;
    }

    std::string_view pattern{argv[1]};
    std::string directory{argv[2]};

    std::cout << "Starting mygrep...\n";
    std::cout << "Pattern to find: " << pattern << "\n";
    std::cout << "Directory to search: " << directory << "\n";

    auto matches = search_files(directory, pattern);
    for (const auto& match: matches) {
        std::cout << match << "\n";
    }

    return 0;
}