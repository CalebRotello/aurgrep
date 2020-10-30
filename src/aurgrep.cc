
#include "utilities.h"
#include "greper.h"

#include <fstream>

int main(int argc, char** argv) {

    /* parse cli */
    Settings::read_settings(argc, argv);
    Greper greper = Greper();

    /* do software */
    if (Settings::exec_type == Settings::ExecutionType::SEARCH) {
        for (auto pkg : Settings::pkglist) {
            greper.search(pkg);
        }
    } else if (Settings::exec_type == Settings::ExecutionType::DOWNLOAD) {
        for (auto pkg : Settings::pkglist) {
            greper.download(pkg);        
        }
    } 

    return 0;
}