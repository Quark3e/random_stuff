#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
//#include "itemList.h"
using namespace std;

int itemsArray[6];
string itemsNameArray[6];

int main() {
    bool loopVal = true;
    int options;

    while(loopVal) {

    }

    return 0;
}

void option1() {
    //get item stat from name and abilityType
}
void option2() {
    
}


void Mythic_items(string itemName, string abilityType) {
    itemsArray[0] = get_itemStat(itemName, abilityType, Mythic);
}
void Legendary_items(string itemName, string abilityType, int i ) {
    itemsArray[i] = get_itemStat(itemName, abilityType, Legendary);
}

int get_itemStat(string itemName, string abilityType, string itemType) {
    int itemStat;

    if (itemType == "Mythic") {
        
    }
    else if (itemType == "Legendary") {

    }
    else {}

    return itemStat;
}

//champion/ad/ap/crit/atk/leth/armorPen/omnivamp/lifesteal/abilityHaste/health/mana/armor/mr/healthRegen/manaRegen