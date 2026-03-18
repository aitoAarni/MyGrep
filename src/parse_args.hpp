#pragma once
#include <string_view>
#include <string>
#include <optional>
#include <iostream>

struct Options {
    std::string_view pattern;
    std::string directory;
    bool counts = false;
};

inline std::ostream& operator<<(std::ostream& os, Options options) {
    os << "pattern: " << options.pattern << "\n";
    os << "directory: " << options.directory << "\n";
    os << "counts: " << options.counts;
    return os;
}


std::optional<Options> parse_args(const int argc, char* argv[]);