#include <unistd.h>
#include "parse_args.hpp"


std::optional<Options> parse_args(const int argc, char* argv[]) {
    int opt;
    auto options = Options();
    while((opt = getopt(argc, argv, "c")) != -1) { 
        switch(opt) 
        { 
            case 'c': 
                options.counts = true;
                break; 
            default: 
                return std::nullopt;
        } 
    } 

    if (optind + 2 > argc) {
        std::cerr << "Usage: " << argv[0] << " <pattern> <directory>\n";
        return std::nullopt;
    }
    options.pattern = argv[optind++];
    options.directory = argv[optind++];
    
    return options;
}