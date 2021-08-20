#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <windows.h>
#include "highestStatFinder.h"
using namespace std;

int itemCombo(string item1_mythic,string item2_legen,string item3_legen,string item4_legen,string item5_legen,string abilityType);
int abilityType_StringToInt(string abilityType);
int itemRow_finder(string itemName);
int itemStat(int rowLine, string abilityType);
string stringFinder(int rowLine);
void itemPrefix_specifier(string abilityspecifier);
int totalItemStatCalculator();
void bastardMisspelled();


void option1();
void option2();
void option3();

int itemsStatArray[6];
string itemsNameArray[6];
int comboItemStatArray[6];
string comboItemNameArray[6];
string highestStatItemName_Array[10];
double comboVal;
string itemPrefix;
int itemStatusNumber;
int arrayWhatToShow = 0;


int main() {
    bool loopVal = true;
    int options;

    while(loopVal) {
        cout << "Options:\n1.See item stat from item\n";
        cout << "2.Get a sum of stat from 1 mythic and 4 legendary items\n";
        cout << "3.Get item with the highest item stat\n";
        cout << "4.Get best combination of 1 Mythic and 4 Legendary items for a certain item stat\n";
        cout << "5.Exit program\n";
        cout << "Enter option: ";
        cin >> options;
        if (cin.fail()) {
            cout << options << " :is an invalid answer.\n";
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
                option4();
                Sleep(1500);
                break;
            case 5:
                cout << "exiting.";
                for(int i=0; i<=1; i++) {Sleep(800); cout << " .";}
                return 0;
            default:
                cout << options << " is an invalid answer.\n";
        }
        system("pause");
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
    itemStatusNumber = 0;
    itemStat(itemRow_finder(itemName), abilityType);
    if (itemStatusNumber == 69) {return;}
    //else {
        cout << "\n" << itemName << ": " << abilityType << "=\n";
        cout << itemStatusNumber << endl;
    //}

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
    cout << "\nEnter item stat: ";
    cin >> abilityType;
    cout << "\nProcessing.";
    for (int i=0; i<2; i++) {cout << " .";Sleep(800);}
    int returnVal = itemCombo(MythicItem, LegenItem1, LegenItem2, LegenItem3, LegenItem4, abilityType);
    int totalVal = totalItemStatCalculator();
    itemPrefix_specifier(abilityType);
    if (returnVal == 69) {cout << "ah shit\n"; return;}
    else if (returnVal == 0) { 
        cout << "\nTotal " << abilityType << " for:\n";
        cout << MythicItem << ", " << LegenItem1 << ", " << LegenItem2 << ", " << LegenItem3 << ", " << LegenItem4 << "\n= ";
        cout << totalVal << " " << itemPrefix << endl;
    }
    else {cout << "\nerror.\n";}

}

void option3() {
    //Find item with highest stat of a certain item stat.
    string abilityType;
    string itemType;

    cout << "\nEnter either Mythic or Legendary: ";
    cin >> itemType;
    cout << "\nEnter item stat to get highest item for: ";
    cin >> abilityType;
    highestStat_Finder(abilityType, itemType);
    cout << "The item(s) with the highest " << abilityType;
    if(arrayWhatToShow == 0) {cout << " is:\n";}
    else{cout << " are:\n";} 
    for(int i=0; i<=arrayWhatToShow; i++) {
        cout << highestStatItemName_Array[i] << "\n";
    }

}

void option4() {
    //Find best combination of 1 mythic and 4 legendary to get an item stat as high as possible.
    string AbilityType;


}

void randomItem_Selector() {
    //Edit's the global comboItemNameArray[] with 1 mythical and 4 Legendary items. Then edits the global comboVal
    //variable with the comboValEditor() function

}

void highestStat_Finder(string abilityType, string itemType) {
    int var1;
    int var2;
    int i = 1;
    int arrayCount = 0;
    arrayWhatToShow = 0;
    string currentStatus = "notEqual";
    
    if (itemType == "Mythic") {
        var1 = itemStat(i, abilityType);
        highestStatItemName_Array[0] = getItemName_fromrowLine(i);
        for(i=2; i<=23; i++) {
            var2 = itemStat(i, abilityType);
            //string function_result = Comparer_bigger(var1, var2);
            if(var1>var2) {
                //represents previous line
                }
            else if(var1<var2) {
                //represents current/new line
                highestStatItemName_Array[0] = getItemName_fromrowLine(i);
                arrayWhatToShow = 0;
                arrayCount = 0;
                currentStatus = "notEqual";
                var1 = var2;
                }
            else if(var1 == var2) {
                if(currentStatus == "Equal") {
                    arrayWhatToShow++;
                    arrayCount++;
                    highestStatItemName_Array[arrayCount] = getItemName_fromrowLine(i);
                }
                else if(currentStatus == "notEqual") {
                    currentStatus = "Equal";
                    arrayWhatToShow++;
                    arrayCount++;
                    highestStatItemName_Array[arrayCount] = getItemName_fromrowLine(i);
                }
            }
        }
    }
    else if (itemType == "Legendary") {
        var1 = itemStat(i, abilityType);
        highestStatItemName_Array[0] = getItemName_fromrowLine(i);
        for(i=26; i<=89; i++) {
            var2 = itemStat(i, abilityType);
            //string function_result = Comparer_bigger(var1, var2);
            if(var1>var2) {
                //represents previous line
                }
            else if(var1<var2) {
                //represents current/new line
                highestStatItemName_Array[0] = getItemName_fromrowLine(i);
                arrayWhatToShow = 0;
                arrayCount = 0;
                currentStatus = "notEqual";
                var1 = var2;
                }
            else if(var1 == var2) {
                if(currentStatus == "Equal") {
                    arrayWhatToShow++;
                    arrayCount++;
                    highestStatItemName_Array[arrayCount] = getItemName_fromrowLine(i);
                }
                else if(currentStatus == "notEqual") {
                    currentStatus = "Equal";
                    arrayWhatToShow++;
                    arrayCount++;
                    highestStatItemName_Array[arrayCount] = getItemName_fromrowLine(i);
                }
            }
        }
    }
}

string getItemName_fromrowLine(int rowLine) {
    string itemName;
    string s;
    string delimiter = "/";
    size_t pos = 0;
    ifstream myfile("itemList.txt");
    if (myfile.is_open()) {
        for(int i=0; i<=rowLine; i++) {
            getline(myfile, s);
            pos = s.find(delimiter);
            itemName = s.substr(0, pos);
            s.erase(0, pos + delimiter.length());
        }
    }
    else {cout << "Unable to open file\n";}
    myfile.close();

    return itemName;
}

int itemCombo(string item1_mythic,string item2_legen,string item3_legen,string item4_legen,string item5_legen,string abilityType) {
    //build item stat sum of 5 items (1 mythic, 4 legendary)
    int answer;
    int failed_returnVal = 69;
    itemStatusNumber = 0;
    itemStat(itemRow_finder(item1_mythic), abilityType);
    if (itemStatusNumber == 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[0] = itemStatusNumber;
    itemsNameArray[0] = item1_mythic;
    itemStat(itemRow_finder(item2_legen), abilityType);
    if (itemStatusNumber == 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[1] = itemStatusNumber;
    itemsNameArray[1] = item2_legen;
    itemStat(itemRow_finder(item3_legen), abilityType);
    if (itemStatusNumber == 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[2] = itemStatusNumber;
    itemsNameArray[2] = item3_legen;
    itemStat(itemRow_finder(item4_legen), abilityType);
    if (itemStatusNumber == 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[3] = itemStatusNumber;
    itemsNameArray[3] = item4_legen;
    itemStat(itemRow_finder(item5_legen), abilityType);
    if (itemStatusNumber == 69) {bastardMisspelled(); return failed_returnVal;}
    itemsStatArray[4] = itemStatusNumber;
    itemsNameArray[4] = item5_legen;

    // for (int i=0; i<5; i++) {
    //     cout << "\n" << itemsNameArray[i];
    //     cout << itemsStatArray[i];
    //     cout << "-.-.-.-.-";
    // }
    itemStatusNumber = 0;
    return 0;
}

int abilityType_StringToInt(string abilityType) {
    int abilityTypeVar = 0;
    int false_check = 1;
    
    itemPrefix_specifier(abilityType);

    if (abilityType == "AttackDamage") {
        abilityTypeVar = 2;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "AbilityPower") {
        abilityTypeVar = 3;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "CriticalStrike") {
        abilityTypeVar = 4;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "AttackSpeed") {
        abilityTypeVar = 5;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "Lethality") {
        abilityTypeVar = 6;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "ArmorPenetration") {
        abilityTypeVar = 7;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "Omnivamp") {
        abilityTypeVar = 8;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "LifeSteal") {
        abilityTypeVar = 9;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "AbilityHaste") {
        abilityTypeVar = 10;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "Health") {
        abilityTypeVar = 11;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "Mana") {
        abilityTypeVar = 12;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "Armor") {
        abilityTypeVar = 13;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "MagicResistance") {
        abilityTypeVar = 14;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "HealthRegen") {
        abilityTypeVar = 15;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "ManaRegen") {
        abilityTypeVar = 16;
        false_check = 0;
        return abilityTypeVar;
        }
    else if (abilityType == "ApPenetration") {
        abilityTypeVar = 17;
        false_check = 0;
        return abilityTypeVar;
        }
    if (false_check = 1) {abilityTypeVar = 69; return abilityTypeVar;}

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
            if (itemName == s.substr(0, pos)) {break;}
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
    if (s == "69") {cout << "bastard misspelled the item name: " << rowLine << endl; return_failed = 69; return return_failed;}
    if (ItemStatType == 69) {cout << "ya misspelled the item stat fucko. Start again"; return_failed = 69; return return_failed;}
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
    itemStatusNumber = itemStat;
    //cout << itemStatusNumber;
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

void itemPrefix_specifier(string abilityspecifier) {
    if (abilityspecifier == "AttackDamage") {itemPrefix = "AD";}
    else if (abilityspecifier == "AbilityPower") {itemPrefix = "AP";}
    else if (abilityspecifier == "CriticalStrike") {itemPrefix = "%. crit";}
    else if (abilityspecifier == "AttackSpeed") {itemPrefix = "%. atk";}
    else if (abilityspecifier == "Lethality") {itemPrefix = "Lethalilty";}
    else if (abilityspecifier == "ArmorPenetration") {itemPrefix = "Armor pen.";}
    else if (abilityspecifier == "Omnivamp") {itemPrefix = "Omnivamp";}
    else if (abilityspecifier == "LifeSteal") {itemPrefix = "LifeSteal";}
    else if (abilityspecifier == "AbilityHaste") {itemPrefix = "AH";}
    else if (abilityspecifier == "Health") {itemPrefix = "Health";}
    else if (abilityspecifier == "Mana") {itemPrefix = "Mana";}
    else if (abilityspecifier == "Armor") {itemPrefix = "Armor";}
    else if (abilityspecifier == "MagicResistance") {itemPrefix = "MR";}
    else if (abilityspecifier == "HealthRegen") {itemPrefix = "%. Health regen.";}
    else if (abilityspecifier == "ManaRegen") {itemPrefix = "%. Mana regen.";}
    else if (abilityspecifier == "ApPenetration") {itemPrefix = "%. AP pen";}

}

int totalItemStatCalculator() {
    int totalVal = 0;
    for (int i=0; i<=4; i++) {
        totalVal = totalVal + itemsStatArray[i];
    }
    return totalVal;
}

void bastardMisspelled() {
        cout << "trade offer: You misspell one item. I get to make you redo it.\n";
        Sleep(500);
        cout << "redo it\n";
}
//champion/ad/ap/crit/atk/leth/armorPen/omnivamp/lifesteal/abilityHaste/health/mana/armor/mr/healthRegen/manaRegen/apPen