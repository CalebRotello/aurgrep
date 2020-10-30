
#include "utilities.h"

#include <cstring>
#include <string.h>
#include <iostream>

Settings::Settings(int& argc, char** argv) {
    try {
        if (argc < 2 || argv[1][0] != '-') {
            throw std::invalid_argument("Expected argument, none found.");
        } else {
            /* run help */
            if (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0) {
                std::cout << "-s, --search <pkgname>\tSearch for the package in the AUR\n";
                std::cout << "-d, --download <pkgname>Download the package from the AUR\n";
                this->exec_type = ExecutionType::HELP;
            /* run package download */
            } else if (strcmp("-d", argv[1]) == 0 || strcmp("--download", argv[1]) == 0) {
                if (argc < 3) {
                    throw std::invalid_argument("Expected package name, none found.");
                } else {
                    this->query = argv[2];
                    this->exec_type = ExecutionType::DOWNLOAD;
                }
            /* run package search */
            } else if (strcmp("-s", argv[1]) == 0 || strcmp("--search", argv[1]) == 0) {
                if (argc < 3) {
                    throw std::invalid_argument("Expected package name, none found.");
                } else {
                    this->exec_type = ExecutionType::SEARCH;
                }
            } else {
                throw std::invalid_argument("Command not recognized.");
            }

        }
    } catch (std::invalid_argument& e) {
        std::cerr << "ERROR: " << e.what() << std::endl; 
    }
}

const std::string& Settings::get_query() const {
    return this->query;
}

const ExecutionType& Settings::get_exec_type() const {
    return this->exec_type;
}
