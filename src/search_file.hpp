#pragma once
#include <string>
#include <vector>
#include <string_view>
#include <filesystem>
#include <ostream>
#include <cstddef>

namespace fs = std::filesystem; 

struct LineMatch {
    std::string line;
    std::vector<int> match_starts;    
    int line_num;
    std::size_t match_size;
};

inline std::ostream& operator<<(std::ostream& os, const LineMatch& line_match) {
    std::string_view line_sw (line_match.line);
    int current_pos {0};
    os << "(line " << line_match.line_num << "): ";
    for (const int& match_pos : line_match.match_starts) {
        os << line_sw.substr(current_pos, match_pos - current_pos);
        os << "\033[1m\033[34m";
        os << line_sw.substr(match_pos, line_match.match_size);
        os << "\033[0m";
        current_pos = match_pos + line_match.match_size;
    }
    os << line_sw.substr(current_pos, line_sw.size() - current_pos);
    return os;
}



struct FileMatch {
    std::string file; 
    std::vector<LineMatch> line_matches;
};

inline std::ostream& operator<<(std::ostream& os, const FileMatch& file_match) {
    for (const auto& line_match : file_match.line_matches) {
        os << file_match.file << " " << line_match;
    }
    return os;
}

std::vector<LineMatch> search_pattern(const fs::directory_entry& filename, const std::string_view match);
std::vector<FileMatch> search_files(const std::string& filename, const std::string_view match);