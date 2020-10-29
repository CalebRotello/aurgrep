
#ifndef DOWNLOAD_H_
#define DOWNLOAD_H_

#include <string>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <filesystem>
#include <cstdint>
#include <cstring>


namespace fs = std::filesystem;

class Greper {
    const std::string AUR_SEARCH = "https://aur.archlinux.org/packages/";
    std::string PKGNAME;
    std::string GIT_DIR = "aur/";
    std::string AUR_CLONE_URL;
    std::string SYS_PKG_LOC;

public:
    Greper();

    void download(const std::string& pkgname); 
    void check_repo();
    void is_installed();
    void meta_dir_setup();
};

#endif /* DOWNLOAD_H_ */