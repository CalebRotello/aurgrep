
#include "download.h"

void download(const std::string& pkgname) {

    const std::string AUR_CLONE_URL = "https://aur.archlinux.org/" + pkgname + ".git";

    system(("git clone "+AUR_CLONE_URL).c_str());
}