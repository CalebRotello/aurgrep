
#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <cstdint>
#include <string>

enum ExecutionType : std::uint_least8_t {
    HELP,
    DOWNLOAD,
    SEARCH,
};

//ExecutionType parse_command_line(int& argc, char** argv);

class Settings {
    std::string query;    
    ExecutionType exec_type;

public:
    Settings(int& argc, char** argv);

    const std::string& get_query() const;
    const ExecutionType& get_exec_type() const;
};

#endif /* UTILITIES_H_ */