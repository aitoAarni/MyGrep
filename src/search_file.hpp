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



struct FileMatch {
    std::string file; 
    std::vector<LineMatch> line_matches;
};

std::vector<LineMatch> search_pattern(const fs::directory_entry& filename, const std::string_view match);
std::vector<FileMatch> search_files(const std::string& filename, const std::string_view match);