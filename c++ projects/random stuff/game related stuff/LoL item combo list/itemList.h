#include <iostream>
#include <string>
using namespace std;

int itemRow_finder(string itemName) {
    int loopCount = 1;
    bool loopVal = true;
    string s;
    string delimiter = "/";
    size_t pos = 0;
    ifstream myfile("itemList.txt");
    if (myfile.is_open()) {
        while (loopVal) {
            getline(myfile, s);
            pos = s.find(delimiter);
            if (Champion == s.substr(0, pos)) {break;}
            s.erase(0, pos + delimiter.length());
            loopCount = loopCount + 1;
            if (myfile.eof()) {loopCount = 0; break;}
        }
    }
    else {cout << "Unable to open file\n";}
    return loopCount;
}

int itemStat(int rowLine, int abilityType) {
    string s = txtFileFinder(rowLine);
    int lvl = levelRounder(i)+1;
    int loopCount = 0;
    int returnVal;
    string delimiter = "/";
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        pos = s.find(delimiter);
        token = s.substr(0, pos);
        if (pos > string::npos) {break;}
        s.erase(0, pos + delimiter.length());
        loopCount = loopCount + 1;
        if (loopCount >= lvl) {break;}
    }
    if (lvl>1) {returnVal = stoi(token);}
    else {returnVal = 0;}
    return returnVal;
}

string stringFinder(int rowLine) {
    string line;
    ifstream myfile("itemList.txt");
    if (myfile.is_open()) {
        for (int i=1; i<=rowLine; i++) {
            getline(myfile,line);
        }
        myfile.close();
    }

    return line;
}

//champion/ad/ap/crit/atk/leth/armorPen/omnivamp/lifesteal/abilityHaste/health/mana/armor/mr/healthRegen/manaRegen