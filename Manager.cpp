#include <fstream>
#include "Manager.h"

using namespace std;

Manager::Manager(){
    _wallets = vector<Wallet>(0);
}

void Manager::command(string command){
    if(command == "help")
        Manager::help();
    else if(command == "balance")
        Manager::balance();
    else if(command.substr(0,6) == "select")
        Manager::select(command.substr(7,command.size()-7));
    else if(command == "wallets")
        Manager::wallets();
    else if(command == "add")
        cout << Manager::add() << endl << endl;
    else if(command == "list")
        Manager::list();
    else
        cout << "   Unrecognized command." << endl << endl;
}

bool Manager::load(){
    ifstream fin("data.txt");
    char c;
    string s;
    int index = -1;
    while(true){
        fin >> c;
        if(c == '%'){
            getline(fin, s);
            Wallet w(s);
            _wallets.push_back(w);
            index++;
        }
        if(c == '-'){
            getline(fin, s);
            double v;
            int d, m, y;
            fin >> v;
            fin >> d;
            fin >> m;
            fin >> y;
            _wallets[index].add(s,v,d,m,y);
        }
        if(c=='*'){
            break;
        }
    }
    fin.close();
    if(index<0)
        return false;
    _index = 0;
    return true;
}
void Manager::save(){
    ofstream fout("data.txt");
    for(int i = 0;i<_wallets.size();i++){
        fout << "%" << _wallets[i].name() << endl;
        for(int j = 0;j<_wallets[i].size();j++){
            fout << "-" << _wallets[i][j].name() << endl;
            fout << _wallets[i][j].log();
            if(i < _wallets.size())
                if(j < _wallets[i].size())
                    fout << endl;
        }
    }
    fout << "*";
    fout.close();
}

void Manager::help(){
    cout << "Available commands[ver1.0]:" << endl;
    cout << "  'balance'           - prints current balance of selected wallet." << endl;
    cout << "  'select <index>'    - selects a different wallet by its index." << endl;
    cout << "  'wallets'           - lists all available wallets and their respective indexes." << endl;
    cout << "  'add'               - opens a wizard for adding new bill to your selected wallet." << endl;
    cout << "  'list'              - lists all bills from the selected wallet." << endl;
    cout << "  'exit'              - saves data and exits, closing the app using any other method won't save any data." << endl;
    cout << "Any suggestions are welcome, contact: nikola.rasic@elfak.rs" << endl << endl;
}
void Manager::balance(){
    cout << "   '" << _wallets[_index].name() << "' balance: " << _wallets[_index].balance() << "RSD" << endl;
    cout << endl;
}
void Manager::select(string index){
    if(stoi(index)>_wallets.size() || stoi(index)<1)
    {
        cout << "   Invalid index." << endl << endl;
        return;
    }
    try{
        int i = stoi(index);
        _index = i-1;
        cout << "   Selected wallet: '" << _wallets[_index].name() << "'." << endl << endl;
    }
    catch(exception e){
        cout << "   Wrong format." <<  endl << endl;
    }
}
void Manager::wallets(){
    cout << "   Displaying all wallets:" << endl << endl;
    cout << "   index       wallet          balance" << endl;
    cout << "-----------------------------------------" << endl;
    for(int i = 0;i<_wallets.size();i++){
        cout << "   #" << i+1 << "     " << _wallets[i].name();
        cout << "           " << _wallets[i].balance() << "RSD" << endl;
    }
    cout << endl;
}
string Manager::add(){
    cout << "Adding a new bill to '" << _wallets[_index].name() << "'." << endl;
    cout << "Enter Bill's name(type 'abort' anytime if you wish to do so): ";
    string name;
    getline(cin, name);
    if(name == "abort")
        return "process aborted.";
    cout << "Enter value for the new '" << name << "': ";
    string value;
    getline(cin, value);
    if(value == "abort")
        return "process aborted.";
    cout << "Lastly, enter three numbers representing day, month and year of the bill." << endl;
    cout << "Make sure to seperate them with space, tab or enter: ";
    string day, month, year;
    cin >> day;
    if(day == "abort")
        return "process aborted.";
    cin >> month;
    if(month == "abort")
        return "process aborted.";
    cin >> year;
    if(year == "abort")
        return "process aborted.";
    
    _wallets[_index].add(name,stod(value),stoi(day),stoi(month),stoi(year));
    return "sucessfully added.";
}
void Manager::list(){
    cout << "   Displaying all bills from '" << _wallets[_index].name() << "':" << endl << endl;
    cout << "   date        value           name" << endl;
    cout << "--------------------------------------" << endl;
    for(int i = _wallets[_index].size()-1; i >= 0; i--){
        cout << "   " << _wallets[_index][i].date() << "        " << _wallets[_index][i].value();
        cout << "       " << _wallets[_index][i].name() << endl;
    }
    cout << endl;
}