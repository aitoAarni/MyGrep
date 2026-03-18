#include <iostream>
#include <string_view>
#include <string>
#include "search_file.hpp"
#include "parse_args.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <pattern> <directory>\n";
        return 1;
    }
    auto args_box = parse_args(argc, argv);
    if (!args_box) {
        return 1;
    }
    Options args = args_box.value();
    
    std::cout << "Starting mygrep...\n";
    std::cout << args << "\n";

    auto matches = search_files(args.directory, args.pattern);
    for (const auto& match: matches) {
        std::cout << match << "\n";
    }

    return 0;
}