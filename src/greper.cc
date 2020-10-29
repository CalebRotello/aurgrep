
#include "greper.h"

Greper::Greper() {cURLpp::initialize();}//cURLpp:CURL_GLOBAL_ALL);}
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
void Greper::check_repo() {

    /* create request */
    curlpp::options::Url search_url(AUR_SEARCH+PKGNAME);
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
    check_repo();

    /* if install failed, figure stuff out */
    if (http_code != 200) {
        std::cout << pkgname << " not found, exiting..." << std::endl;
        exit(0);
    } else {
        system(("git clone " + AUR_CLONE_URL + " " + SYS_PKG_LOC).c_str());
    }

    /* otherwise, enjoy! */
    
}