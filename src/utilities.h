
#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

namespace Settings {

/** ExecutionType
 * mode this program is running in
 */ 
enum ExecutionType : std::uint_least8_t {
    HELP,
    DOWNLOAD,
    SEARCH,
};

extern std::set<std::string> pkglist;    
extern ExecutionType exec_type;
extern bool SHOW_PKGBUILD;

void show_help();
void read_settings(int& argc, char** argv);

}

#endif /* UTILITIES_H_ */