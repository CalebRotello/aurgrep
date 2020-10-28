
#include "utilities.h"
#include "download.h"

int main(int argc, char** argv) {

    /* parse cli */
    Settings settings = Settings(argc, argv); 

    /* do software */
    if (settings.get_exec_type() == ExecutionType::SEARCH) {

    } else if (settings.get_exec_type() == ExecutionType::DOWNLOAD) {
        download(settings.get_query());        
    }

    return 0;
}