
#include "greper.h"

Greper::Greper() {}

void Greper::meta_dir_setup() {
    const fs::path p = fs::path(GIT_DIR);
    bool make_dir_check = fs::create_directory(p);
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

void Greper::check_repo() {
    /* is this a package? */
    
    //char p_request[100]={0};
 
    ////char p_resourcepath[]="2019/07/creating-xml-request-in-cpp-for-server.html";
    ////std::stp_resourcepath= (AUR_SEARCH+PKGNAME).c_str();
 
    ////char p_hostaddress[]="www.cplusplus.com";
    //const char *p_hostaddress = AUR_SEARCH.c_str();
 
    //sprintf(p_request, "GET %s"/* HTTP/1.1\r\nHost: %s "\r\nContent-Type: text/plain\r\n\r\n", p_resourcepath, p_hostaddress */, (AUR_SEARCH+PKGNAME).c_str());
 
    //std::cout<< p_request;

    //int pd[2];
    //int retValue;
    //char buffer[255] = {0};
    //pipe(pd);
    ////dup2(pd[1],1);
    //retValue = system(("curl  --silent --head \"" + AUR_SEARCH + PKGNAME + "\"  ").c_str());
    ///* yes, this is hacky, but that's what I get for dipping into C for a few lines */
    ////read(pd[0], buffer,  2) > 0; 
    ////fscanf(stdin, "%[^ ]", buffer);
    ////fgets(buffer, 255, stdin);
    ////std::ifstream file(stdin);


    //std::string result = buffer;//std::to_string(buffer);
    //std::cout << result << std::endl;
    //char *delim = " ";
    //char *c = strtok(buffer, delim);
    //printf("%s\n", c);
    //c = strtok(buffer, delim);
    ////printf("%s,\n", buffer);

    //printf("%s\n", c);

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

    /* otherwise, enjoy! */
    
}