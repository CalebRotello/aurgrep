
#include "greper.h"

Greper::Greper() {
    cURLpp::initialize();
    //struct passwd *pw = getpwuid(getuid());
    //const char *homedir = pw->pw_dir;
    this->SYS_USERNAME = std::string(getpwuid(getuid())->pw_dir);//homedir);
    this->GIT_DIR = SYS_USERNAME+"/aur/";
}

Greper::~Greper() {cURLpp::terminate();}

void Greper::meta_dir_setup() {
    const fs::path p = fs::path(GIT_DIR);
    if(fs::create_directory(p))
       std::cout << "Could not find AUR directory, creating " << GIT_DIR << std::endl;
    
}

void Greper::is_installed() {
    const fs::path p = fs::path(SYS_PKG_LOC);
    if (fs::exists(p)) {
        char yes_no = ' ';
        std::cout << "Package directory already exists, would you like to reinstall? (y/n): ";
        while (true) {
            std::cin >> yes_no;
            switch (yes_no) {
                case 'y':
                case 'Y':
                    /* reinstall */
                    std::cout << "Deleting package directory..." << std::endl;
                    fs::remove_all(SYS_PKG_LOC); 
                    return;
                case 'n':
                case 'N':
                    /* exit program gracefully */
                    std::cout << "Finished." << std::endl;
                    exit(0);
            }
        }
    }
}

/* is this a package? */
void Greper::check_repo(const std::string& url) {

    /* create request */
    curlpp::options::Url search_url(url);
    curlpp::Easy request;
    std::stringstream sstr;
    request.setOpt(search_url);
    request.setOpt(new curlpp::options::WriteStream(&sstr));

    /* do request & handle results */
    std::cout << "Searching AUR for package...\n";
    request.perform();
    this->http_code = curlpp::infos::ResponseCode::get(request);  

    std::cout << "Search returned code " << http_code << std::endl;
}

void Greper::download(const std::string& pkgname) {
    /* set Greper vars that are needed for package */
    this->PKGNAME = pkgname;
    this->AUR_CLONE_URL = "https://aur.archlinux.org/" + pkgname + ".git";
    this->SYS_PKG_LOC = GIT_DIR + pkgname;

    /* aur pkg dir */
    meta_dir_setup();

    /* check if package is installed */
    is_installed(); 

    /* check if the link is good */
    check_repo(AUR_PACKAGES+PKGNAME);

    /* if install failed, figure stuff out */
    if (http_code != 200) {

        /* search pacman */
        std::cout << PKGNAME << " not found in the AUR \n\nsearching the official repos..." << std::endl;
        system(std::string("pacman -Ss "+PKGNAME).c_str());
        system(std::string("sudo pacman -S "+PKGNAME).c_str());

        /* search for package in AUR ?*/
        search();

        //exit(0);
    } else {
        std::cout << std::endl;
        system(("git clone " + AUR_CLONE_URL + " " + SYS_PKG_LOC).c_str());
    }
    std::cout << "Finished." << std::endl;
}


void Greper::query() {
    /* create request */
    curlpp::options::Url search_url(AUR_SEARCH);
    curlpp::Easy request;
    std::stringstream sstr;
    request.setOpt(search_url);
    request.setOpt(new curlpp::options::WriteStream(&sstr));

    /* do request & handle results */
    std::cout << "Searching AUR for package...\n";
    request.perform();
    this->http_code = curlpp::infos::ResponseCode::get(request);  
    //std::cout << request << std::endl;

    //std::cout << "Search returned code " << http_code << std::endl;
}

void Greper::search(const std::string &pkgname) {
    this->PKGNAME = pkgname;
    search();
}

void Greper::search() {
    this->AUR_SEARCH = AUR_PACKAGES + "?O=0&SeB=nd&K=" + PKGNAME + "&outdated=&SB=n&SO=a&PP=50&do_Search=Go";
    query();
}