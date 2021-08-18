#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
//#include "itemList.h"
using namespace std;

void Mythic_items(string itemName, string abilityType);
void Legendary_items(string itemName, string abilityType, int i );
int get_itemStat(string itemName, string abilityType, string itemType);

void option1();
void option2();
void option3();

int itemsStatArray[6];
string itemsNameArray[6];

int main() {
    bool loopVal = true;
    int options;

    while(loopVal) {
        cout << "Options:\n1.See item stat from item\n";
        cout << "2.Get a sum of stat from 1 mythic and 4 legendary items\n";
        cout << "3.Get best combination of 1 Mythic and 4 Legendary items for a certain item stat\n";
        cout << "4.Exit program\n"
        cout << "Enter option: ";
        cin >> options;
        if (cin.fail()) {
            cout << options << " :is an invalid answer."
            cin.clear();
            cin.ignore();
        }
        switch (options) {
            case 1:
                option1();
                Sleep(1500);
                break;
            case 2:
                option2();
                Sleep(1500);
                break;
            case 3:
                option3();
                Sleep(1500);
                break;
            case 4:
                cout << "exiting.";
                for(int i=0; i<=2; i++) {Sleep(800); cout << " .";}
                return 0;
            default:
                cout << options << " is an invalid answer.\n";
        }
        
        cout << "\n-------------\n";
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
    }
    return 0;
}

void option1() {
    //get item stat from item name and abilityType
    string itemName;
    string abilityType;
    cout << "Enter item name: ";
    cin >> itemName;
    cout << "\nEnter what type of item stat you want: ";
    cin >> abilityType;
    
    int answer = itemStat(itemRow_finder(itemName), abilityType_StringToInt(abilityType));
    if (answer = 69) {return 0;}
    cout << itemName << ": " << abilityType << "=\n";
    cout << answer << endl;

}
void option2() {
    //Get a total (certain stat) value for 5 items from item names and abilityType.
    string MythicItem;
    string LegenItem1;
    string LegenItem2;
    string LegenItem3;
    string LegenItem4;
    string abilityType;
    cout << "Enter 1 Mythic and 4 Legendary items: ";
    cin >> MythicItem >> LegenItem1 >> LegenItem2 >> LegenItem3 >> LegenItem4;
    cout << "\nProcessing.";
    for (int i=0; i<=3; i++) {
        cout << " .";

        Sleep(800);
    }

}

void option3() {
    //Find best combination of 1 mythic and 4 legendary to get an item stat as high as possible.

}

int itemCombo(string item1_mythic,string item2_legen,string item3_legen,string item4_legen,string item5_legen,string abilityType){
    //build item stat sum of 5 items (1 mythic, 4 legendary)
    int answer;
    int failed_returnVal = 69;
    answer = itemStat(itemRow_finder(item1_mythic), abilityType_StringToInt(abilityType));
    if (answer = 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[0] = answer;
    itemsNameArray[0] = ;
    answer = itemStat(itemRow_finder(item2_legen), abilityType_StringToInt(abilityType));
    if (answer = 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[1] = answer;
    itemsNameArray[1] = ;
    answer = itemStat(itemRow_finder(item2_legen), abilityType_StringToInt(abilityType));
    if (answer = 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[2] = answer;
    itemsNameArray[2] = ;
    answer = itemStat(itemRow_finder(item2_legen), abilityType_StringToInt(abilityType));
    if (answer = 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[3] = answer;
    itemsNameArray[3] = ;
    answer = itemStat(itemRow_finder(item2_legen), abilityType_StringToInt(abilityType));
    if (answer = 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[4] = answer;
    itemsNameArray[4] = ;
    return 0;
}

int abilityType_StringToInt(string abilityType) {
    int abilityTypeVar;

    if (abilityType == "AttackDamage") {abilityTypeVar = 2;}
    else if (abilityType == "AbilityPower") {abilityTypeVar = 3;}
    else if (abilityType == "CriticalStrike") {abilityTypeVar = 4;}
    else if (abilityType == "AttackSpeed") {abilityTypeVar = 5;}
    else if (abilityType == "Lethality") {abilityTypeVar = 6;}
    else if (abilityType == "ArmorPenetration") {abilityTypeVar = 7;}
    else if (abilityType == "Omnivamp") {abilityTypeVar = 8;}
    else if (abilityType == "LifeSteal") {abilityTypeVar = 9;}
    else if (abilityType == "AbilityHaste") {abilityTypeVar = 10;}
    else if (abilityType == "Health") {abilityTypeVar = 11;}
    else if (abilityType == "Mana") {abilityTypeVar = 12;}
    else if (abilityType == "Armor") {abilityTypeVar = 13;}
    else if (abilityType == "MagicResistance") {abilityTypeVar = 14;}
    else if (abilityType == "HealthRegen") {abilityTypeVar = 15;}
    else if (abilityType == "ManaRegen") {abilityTypeVar = 16;}
    else if (abilityType == "ApPenetration") {abilityTypeVar = 17;}
    else {abilityTypeVar = 69;}

    return abilityTypeVar;
}

int itemRow_finder(string itemName) {
    int rowLine = 1;
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
            rowLine = rowLine + 1;
            if (myfile.eof()) {rowLine = 0; break;}
        }
    }
    else {cout << "Unable to open file\n";}
    return rowLine;
}

int itemStat(int rowLine, string abilityType) {
    int itemStat;
    int return_failed;
    string s = stringFinder(rowLine);
    int ItemStatType = abilityType_StringToInt(abilityType);
    if (s == "69") {cout << "bastard misspelled the item name"; return_failed = 69; return return_failed;}
    if (ItemStatType == 69) {cout << "ya misspelled the item stat fucko. Start again"; exit;}
    int loopCount = 0;
    string delimiter = "/";
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        pos = s.find(delimiter);
        token = s.substr(0, pos);
        if (pos > string::npos) {break;}
        s.erase(0, pos + delimiter.length());
        loopCount = loopCount + 1;
        if (loopCount >= ItemStatType) {break;}
    }
    if (ItemStatType>1) {itemStat = stoi(token);}
    else {itemStat = 0;}
    return itemStat;
}

string stringFinder(int rowLine) {
    string line;
    string failed_returnVal;
    if (rowLine == 0) {failed_returnVal = "69"; return failed_returnVal;}
    ifstream myfile("itemList.txt");
    if (myfile.is_open()) {
        for (int i=1; i<=rowLine; i++) {
            getline(myfile,line);
        }
        myfile.close();
    }

    return line;
}

void bastardMisspelled() {
        cout << "trade offer: You misspell one item. I get to make you redo it.\n";
        Sleep(500);
        cout << "redo it\n";
}
//champion/ad/ap/crit/atk/leth/armorPen/omnivamp/lifesteal/abilityHaste/health/mana/armor/mr/healthRegen/manaRegen/apPen