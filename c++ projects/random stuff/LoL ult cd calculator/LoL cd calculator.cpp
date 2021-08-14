#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int ChampionRow_finder(string Champion);
int AbilityStat(int rowLine, int i);
int levelRounder(int i);
string txtFileFinder(int rowLine);
double CD_reduction(double i);
double simpleRound(double x);
double round(double x, double n);
void option1();
void option2();
void option3();

int main() {
    int options;
    bool loopVal = true;

    while (loopVal) {
        cout << "Options:\n1.Get ult CD stats\n2.Get ult CD with AbilityHaste\n3.Manually get cooldown from cd and Ability Haste\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> options;
        if (cin.fail()) {
            cout << "error: wrong input.";
            cin.clear();
            cin.ignore();
        }
        system("cls");

        switch (options) {
            case 1:
                option1();
                Sleep(2000);
                break;
            case 2:
                option2();
                Sleep(2000);
                break;
            case 3:
                option3();
                Sleep(2000);
                break;
            case 4:
                return 0;
            default:
                cout << "invalid option\n";
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                }
        }
        cout << "\n-------------\n";
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
    }
}

void option1() {
    string Champion;
    cout << "Enter champion name: ";
    cin >> Champion;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
    }
    cout << txtFileFinder(ChampionRow_finder(Champion));
}

void option2() {
    string Champion;
    int level;
    int AbilityHaste;
    cout << "Enter champion name: ";
    cin >> Champion;
    cout << "Enter champion's level: ";
    cin >> level;
    cout << "Enter Ability Haste: ";
    cin >> AbilityHaste;
    if (cin.fail()) {
        cout << "error: wrong input.";
        cin.clear();
        cin.ignore();
    }
    double answer;
    double cooldown = AbilityStat(ChampionRow_finder(Champion), level);
    if (cooldown != 0) {
        answer = round(((1-CD_reduction(AbilityHaste))*cooldown), 1);
        cout << Champion << "'s CD with " << AbilityHaste << "Ability Haste is:\n";
        cout << answer << " seconds";
    }
}

void option3() {
    double cooldown;
    double AbilityHaste;

    cout << "Enter cooldown and Ability Haste: ";
    cin >> cooldown >> AbilityHaste;
    cout << cooldown << "s cooldown with " << AbilityHaste << "Ability Haste=\n";
    cout << round(((1-CD_reduction(AbilityHaste))*cooldown), 1);
}

int AbilityStat(int rowLine, int i) {
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

int ChampionRow_finder(string Champion) {
    int loopCount = 1;
    bool loopVal = true;
    string s;
    string delimiter = "/";
    size_t pos = 0;
    ifstream myfile("UltCooldowns.txt");
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

string txtFileFinder(int rowLine) {
    string line;
    ifstream myfile("UltCooldowns.txt");
    if (myfile.is_open()) {
        for (int i=1; i<=rowLine; i++) {
            getline(myfile,line);
        }
        myfile.close();
    }

    return line;
}

int levelRounder(int i) {
    int lvl;
    int returnVal;
    if (i<6) {lvl = i; returnVal = 0; cout << "Level too low. Ult not up yet";}
    else if (i<12) {lvl = 6; returnVal = 1;}
    else if (i<18) {lvl = 12; returnVal = 2;}
    else if (i=18) {lvl = 18; returnVal = 3;}
    else {cout << i << "invalid level (max lvl: 18)"; returnVal = 0;}
    return returnVal;
}

double CD_reduction(double i) {
	double Reduction;
    Reduction = i/(i+100);
    return Reduction;
}

double round(double x, double n) {
double incrAnswer = pow(10, n);
double reducAnswer = pow(10,(0-n));
double detailRound = (simpleRound(x*incrAnswer))*reducAnswer;
return detailRound;
}

double simpleRound(double x) {
double simpleRound = x - floor(x) < 0.5? floor(x) : ceil(x);
return simpleRound;
}
