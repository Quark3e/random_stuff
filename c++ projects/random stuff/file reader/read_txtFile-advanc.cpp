#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

int AbilityStat(int rowLine, int i);
int levelRounder(int i);
string txtFileFinder(int rowLine);
double CDR(double i);
double simpleRound(double x);
double round(double x, double n);
void option1();
void option2();

int main() {
    int options;
    bool loopVal = true;

    while (loopVal) {
        cout << "Options:\n1.Get ult CD stats\n2.Get ult CD with AbilityHaste\n3.Exit:\n";
        cout << "Enter choice: ";
        cin >> options;
        switch (options) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                return 0;
            default:
                cout << "invalid option\n";
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                }
        }
        cout << "\n-------------\n";
    }
}

void option1() {
    int rowLine;
    cout << "Enter txtFile rowline/Champion: ";
    cin >> rowLine;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
    }
    cout << txtFileFinder(rowLine);
}

void option2() {
    int rowLine;
    int level;
    int AbilityHaste;
    cout << "Enter rowline/champion: ";
    cin >> rowLine;
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
    double cooldown = AbilityStat(rowLine, level);
    if (cooldown != 0) {
        answer = round(((1-CDR(AbilityHaste))*cooldown), 1);
        cout << rowLine << "'s CD with " << AbilityHaste << "Ability Haste is:\n";
        cout << answer << " seconds";
    }
}

int AbilityStat(int rowLine, int i) {
    string s = txtFileFinder(rowLine);
    int lvl = levelRounder(i)+1;
    int loopCount = 0;
    int returnVal;
    string delimiter = "|";
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

string txtFileFinder(int rowLine) {
    string line;
    string delimiter = "|";
    ifstream myfile ("UltCooldowns.txt");
    if (myfile.is_open()) {
        for (int i=1; i<=rowLine; i++) {
            getline(myfile,line);
        }
        myfile.close();
    }
    else {cout << "Unable to open file\n";}
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

double CDR(double i) {
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