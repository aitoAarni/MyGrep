#include "handle_output.hpp"
#include <iostream>


HandleOutput::HandleOutput(std::vector<FileMatch>& m, Options& f) :  matches(m), flags(f) {}

void HandleOutput::print_match_count() {
    for (const auto& file_match : matches) {
        auto file_name {file_match.file};
        long matches_in_file {0};
        for (const auto& line_match : file_match.line_matches) {
            matches_in_file += line_match.match_starts.size();
        }
        std::cout << file_name << ": " << matches_in_file << "\n";
    }
}

void HandleOutput::print_results() {
    if (flags.counts) {
        print_match_count();
        return;
    } else {
        for (const auto& match: matches) {
            for (const auto& line : match.line_matches) {
                std::cout << match.file<< " " << line << "\n";
            }
        }
    }
}
    