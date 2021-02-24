#include <iostream>
#include <fstream>
#include "Manager.h"

int main(){
    std::cout << "      Nikola Rasic, Faculty of Electronic Engineering," << std::endl;
    std::cout << "      University of Nis. Wallet Assistant." << std::endl;
    std::cout << "      Type 'help' for list of commands." << std::endl << std::endl;
    Manager manager;
    if(!manager.load()){
        std::cout << "'data.txt' is empty or corrupt. please check." << std::endl;
    }
    try{
        std::string s;
        std::cout << "Wallet>";
        getline(std::cin,s);
        while(s != "exit"){
            manager.command(s);
            std::cout << "Wallet>";
            getline(std::cin, s);
        }
        manager.save();
    }
    catch(...){
        std::cout << "Fatal error. Please contact the developer.";
    }
    return 0;
}