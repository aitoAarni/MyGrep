#pragma once
#include <vector>
#include "search_file.hpp"
#include "parse_args.hpp"

class HandleOutput {
    std::vector<FileMatch>& matches;
    Options& flags;
    void print_match_count();
    public:

    HandleOutput(std::vector<FileMatch>& m, Options& f);
    void print_results();
};