
#include "utilities.h"

namespace Settings {

/* namespace variable initialization */
std::set<std::string> pkglist = std::set<std::string>();
ExecutionType exec_type = HELP;
bool SHOW_PKGBUILD = false;

void read_settings(int& argc, char** argv) {
    // read args into a set except last one
    std::set<std::string> arglist = std::set<std::string>();
    std::string argstr;
    if (argc == 1) {
        show_help();
        return;
    }
    for (int i = 1; i < argc; i++) {
        argstr = argv[i];

        // full word command
        if (argstr.find("--") == 0) {//< argstr.length()-2) {
            arglist.insert(argstr.substr(2));
        // single letter commands
        } else if (argstr[0] == '-') {
            for (size_t c = 1; c < argstr.length(); c++) {
                arglist.insert(std::string(1, argstr[c]));
            }
        // package
        } else {
            pkglist.insert(argstr);
        }
    }

    // set system settings
    if (arglist.count("h") || arglist.count("help")) {
        exec_type = HELP;
        show_help();
    }
    else if (arglist.count("S") || arglist.count("download"))
        exec_type = DOWNLOAD;
    else if (arglist.count("s") || arglist.count("search"))
        exec_type = SEARCH;

    if (arglist.count("v") || arglist.count("show"))
        SHOW_PKGBUILD = true;

    return;
}

void show_help() {
    std::cout << 
   "-h, --help     Show this help.\n\
    -d, --download Download an AUR package.\n\
    -v, --show     Show PKGBUILD after downloading.\n\
    -s, --search   Search the AUR for a package.\n\
    \n"
    ;
}
}
