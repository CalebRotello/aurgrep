
#include "utilities.h"
#include "greper.h"

int main(int argc, char** argv) {

    /* parse cli */
    Settings settings = Settings(argc, argv); 
    Greper greper = Greper();

    /* do software */
    if (settings.get_exec_type() == ExecutionType::SEARCH) {

    } else if (settings.get_exec_type() == ExecutionType::DOWNLOAD) {
        greper.download(settings.get_query());        
    }

    return 0;
}