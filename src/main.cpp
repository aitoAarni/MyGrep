#include <iostream>
#include <string_view>

int main(int argc, char* argv[]) {
    // std::span would be great here, but let's keep it simple for step 1
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <pattern> <directory>\n";
        return 1;
    }

    std::string_view pattern{argv[1]};
    std::string_view directory{argv[2]};

    std::cout << "Starting mygrep...\n";
    std::cout << "Pattern to find: " << pattern << "\n";
    std::cout << "Directory to search: " << directory << "\n";

    return 0;
}