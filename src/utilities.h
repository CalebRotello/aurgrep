
#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <cstdint>
#include <string>

/** ExecutionType
 * mode this program is running in
 */ 
enum ExecutionType : std::uint_least8_t {
    HELP,
    DOWNLOAD,
    SEARCH,
};

/** Settings
 * handle program meta events
 */ 
class Settings {
    std::string query;    
    ExecutionType exec_type;

public:
    /** ctor.
     * parse command line flags
     */ 
    Settings(int& argc, char** argv);

    const std::string& get_query() const;
    const ExecutionType& get_exec_type() const;
};

#endif /* UTILITIES_H_ */