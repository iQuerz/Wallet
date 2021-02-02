#pragma once
#include <vector>
#include "Wallet.h"

class Manager{
private:
   std::vector<Wallet> _wallets;
   int _index;
public:
    Manager();
    void command(std::string command);
    bool load();
    void save();
private:
    void help();
    void balance();
    void select(std::string index);
    void wallets();
    std::string add();
    void list();
};