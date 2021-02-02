#pragma once
#include <iostream>

class Bill{
private:
    std::string _name;
    double _value;
    int _day;
    int _month;
    int _year;
    std::string Month(){
        switch (_month){
            case 1:
                return "Jan";
            case 2:
                return "Feb";
            case 3:
                return "Mar";
            case 4:
                return "Apr";
            case 5:
                return "May";
            case 6:
                return "Jun";
            case 7:
                return "Jul";
            case 8:
                return "Aug";
            case 9:
                return "Sep";
            case 10:
                return "Oct";
            case 11:
                return "Nov";
            case 12:
                return "Dec";
        }
        return "error";
    }
public:
    Bill(){}
    Bill(std::string n, double v, int d, int m, int y)
        :_name(n),_value(v),_day(d),_month(m),_year(y){}
    std::string date(){ //returns string for displaying the payment date
        std::string ret = "";
        ret.append(std::to_string(_day));
        ret.append("-");
        ret.append(Month());
        ret.append("-");
        ret.append(std::to_string(_year));
        return ret;
    }
    inline double value(){ return _value; }
    inline std::string name(){ return _name; }
    inline std::string log(){ //returns string ready to save to a file
        std::string ret = "";
        ret.append(std::to_string(_value));
        ret.append(" ");
        ret.append(std::to_string(_day));
        ret.append(" ");
        ret.append(std::to_string(_month));
        ret.append(" ");
        ret.append(std::to_string(_year));
        return ret;
    }
};