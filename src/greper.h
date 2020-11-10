
#ifndef DOWNLOAD_H_
#define DOWNLOAD_H_

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <memory>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <regex>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

#include "utilities.h"

namespace fs = std::filesystem;

/** Greper
 *  the superclass which stores all of the state information about this software
 */ 
class Greper {
    const std::string AUR_PACKAGES = "https://aur.archlinux.org/packages/";
    //const std::string PACMAN_PACKAGES = "https://archlinux.org/packages/";
    std::string PKGNAME;

    /* search only */
    std::string AUR_SEARCH;

    /* download only */
    std::string GIT_DIR;
    std::string AUR_CLONE_URL;
    std::string SYS_PKG_LOC;
    std::string SYS_USERNAME;

    int http_code;

public:
    Greper();
    ~Greper();

    /** search
     * search for a package name
     */
    void search(const std::string& pkgname); 
    /* if meta info is already built */
    void search();

    /** query
     * do https request to search the AUR by name
     */
    void query(); 

    /* WARNING -- this function changes the string passed to it */
    void clean(std::string& search_response);

    /** download
     *  if download is the option, called from main
     */ 
    void download(const std::string& pkgname); 

    /** check_repo
     *  validate that the queried repo exists in AUR 
     */ 
    void check_repo(const std::string& url);

    /** is_installed
     *  if the repo is already installed ask user input
     */ 
    void is_installed();

    /** meta_dir_setup
     *  we need a directory to keep each package 
     */ 
    void meta_dir_setup();

    /** show_pkgbuild
     *  print the pkgbuild file
     */ 
    void show_pkgbuild(const std::string& pkgname);

};

#endif /* DOWNLOAD_H_ */