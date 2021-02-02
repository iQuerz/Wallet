#pragma once
#include <iostream>
#include <vector>
#include "Bill.h"

class Wallet{
private:
    std::string _name;
    std::vector<Bill> _bills;
public:
    Wallet(){
        Wallet("error");
    }
    Wallet(std::string n) {
        _name = n;
        _bills = std::vector<Bill>(0); 
    }
    double balance(){
        double bal;
        for(Bill b : _bills)
            bal += b.value();
        return bal;
    }
    void add(std::string name, double value, int day, int month, int year){
        Bill temp(name,value,day,month,year);
        _bills.push_back(temp);
    }
        
    inline int size(){ return _bills.size(); }
    inline std::string name(){ return _name; }
    inline Bill operator[](int index){ return _bills[index]; }
};