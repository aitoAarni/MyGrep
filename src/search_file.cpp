#include "search_file.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>


namespace fs = std::filesystem;


std::vector<FileMatch> search_files(const std::string& path_string, const std::string_view match) {

    fs::path root_path {path_string};
    fs::directory_entry root_entry (root_path);
    std::vector<FileMatch> matches;
    if (root_entry.is_directory()) {
        
        for (const auto& file : fs::recursive_directory_iterator(root_entry)) {
            if (!file.is_directory()) {
                auto result = search_pattern(file, match);
                if (result.size()) {
                    matches.emplace_back(file.path(), std::move(result));
                }
            }
        }
    }
    else {
        auto result = search_pattern(root_entry, match);
        if (result.size()) {
            matches.emplace_back(root_entry.path(), std::move(result));
        }

    }
    return matches;
}

std::vector<LineMatch> search_pattern(const fs::directory_entry& file, const std::string_view match) {
    std::ifstream file_stream(file.path());
    if (!file_stream) {
        std::cerr << "mygrep: '" << file.path().string() << "' failed to open\n";
    }
    std::string line {};
    std::vector<LineMatch> matches{};
    int line_num {0};
    while (std::getline(file_stream, line)) {
        ++line_num;
        auto found_match = std::search(line.begin(), line.end(), match.begin(), match.end());
        if (found_match == line.end()) continue;
        std::vector<int> match_starts;
        while (found_match != line.end()) {
            int column_num {static_cast<int>(std::distance(line.begin(), found_match))};
            match_starts.push_back(column_num);
            std::advance(found_match, match.size());
            found_match = std::search(found_match, line.end(), match.begin(), match.end());
        }
        matches.emplace_back(line, std::move(match_starts), line_num, match.size());
        std::cout << "printing LineMatch" << "\n";
        std::cout << matches.back() << "\n";
    }
    return matches;
}