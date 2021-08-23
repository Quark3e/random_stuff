#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <windows.h>
using namespace std;

// double comboValEditor(string itemName) {
//     double returnComboVal;
//     //mythic items
//     if (itemName == "Divine_Sunderer") {returnComboVal = 0.01;}
//     else if (itemName == "Duskblade_of_draktharr") {returnComboVal = 0.02;}
//     else if (itemName == "Eclipse") {returnComboVal = 0.03;}
//     else if (itemName == "Everfrost") {returnComboVal = 0.04;}
//     else if (itemName == "Frostfire_Gauntlet") {returnComboVal = 0.05;}
//     else if (itemName == "Galeforce") {returnComboVal = 0.06;}
//     else if (itemName == "Goredrinker") {returnComboVal = 0.07;}
//     else if (itemName == "Hextech_Rocketbelt") {returnComboVal = 0.08;}
//     else if (itemName == "Immortal_Shieldbow") {returnComboVal = 0.09;}
//     else if (itemName == "Imperial_Mandate") {returnComboVal = 0.10;}
//     else if (itemName == "Kraken_Slayer") {returnComboVal = 0.11;}
//     else if (itemName == "Liandry's_Anguish") {returnComboVal = 0.12;}
//     else if (itemName == "Locket_of_the_Iron_Solari") {returnComboVal = 0.13;}
//     else if (itemName == "Luden's_Tempest") {returnComboVal = 0.14;}
//     else if (itemName == "Moonstone_Renewer") {returnComboVal = 0.15;}
//     else if (itemName == "Night_Harvester") {returnComboVal = 0.16;}
//     else if (itemName == "Prowler's_Claw") {returnComboVal = 0.17;}
//     else if (itemName == "Riftmaker") {returnComboVal = 0.18;}
//     else if (itemName == "Shurelya's_Battlesong") {returnComboVal = 0.19;}
//     else if (itemName == "Stridebreaker") {returnComboVal = 0.20;}
//     else if (itemName == "Sunfire_Aegis") {returnComboVal = 0.21;}
//     else if (itemName == "Trinity_Force") {returnComboVal = 0.22;}
//     else if (itemName == "Turbo_Chemtank") {returnComboVal = 0.23;}
//     //legendary items
//     else if (itemName == "Abyssal_Mask") {returnComboVal = 1;}
//     else if (itemName == "Anathema's_Chains") {returnComboVal = 2;}
//     else if (itemName == "Archhangel's_Staff") {returnComboVal = 3;}
//     else if (itemName == "Ardent_Censer") {returnComboVal = 4;}
//     else if (itemName == "Banshee's_Veil") {returnComboVal = 5;}
//     else if (itemName == "Black_Cleaver") {returnComboVal = 6;}
//     else if (itemName == "Blade_of_the_Ruined_King") {returnComboVal = 7;}
//     else if (itemName == "Bloodthirster") {returnComboVal = 8;}
//     else if (itemName == "Bulwark_of_the_Mountain") {returnComboVal = 9;}
//     else if (itemName == "Chempunk_Chainsword") {returnComboVal = 10;}
//     else if (itemName == "Chemtech_Putrifier") {returnComboVal = 11;}
//     else if (itemName == "Cosmic_Drive") {returnComboVal = 12;}
//     else if (itemName == "Dead_Man's_Plate") {returnComboVal = 13;}
//     else if (itemName == "Death's_Dance") {returnComboVal = 14;}
//     else if (itemName == "Demonic_Embrace") {returnComboVal = 15;}
//     else if (itemName == "Edge_of_Night") {returnComboVal = 16;}
//     else if (itemName == "Essence_Reaver") {returnComboVal = 17;}
//     else if (itemName == "Force_of_Nature") {returnComboVal = 18;}
//     else if (itemName == "Frozen_Heart") {returnComboVal = 19;}
//     else if (itemName == "Gargoyle_Stoneplate") {returnComboVal = 20;}
//     else if (itemName == "Guardian_Angel") {returnComboVal = 21;}
//     else if (itemName == "Guinsoo's_Rageblade") {returnComboVal = 22;}
//     else if (itemName == "Horizon_Focus") {returnComboVal = 23;}
//     else if (itemName == "Hullbreaker") {returnComboVal = 24;}
//     else if (itemName == "Infinity_Edge") {returnComboVal = 25;}
//     else if (itemName == "Knight's_Vow") {returnComboVal = 26;}
//     else if (itemName == "Lich_Bane") {returnComboVal = 27;}
//     else if (itemName == "Lord_Dominik's_Regards") {returnComboVal = 28;}
//     else if (itemName == "Manamune") {returnComboVal = 29;}
//     else if (itemName == "Maw_of_Malmortious") {returnComboVal = 30;}
//     else if (itemName == "Mejai's_Soulstealer") {returnComboVal = 31;}
//     else if (itemName == "Mercurial_Scimitar") {returnComboVal = 32;}
//     else if (itemName == "Mikael's_Blessing") {returnComboVal = 33;}
//     else if (itemName == "Morellonomicon") {returnComboVal = 34;}
//     else if (itemName == "Mortal_Reminder") {returnComboVal = 35;}
//     else if (itemName == "Muramana") {returnComboVal = 36;}
//     else if (itemName == "Nashor's_Tooth") {returnComboVal = 37;}
//     else if (itemName == "Navori_Quickblades") {returnComboVal = 38;}
//     else if (itemName == "Phantom_Dancer") {returnComboVal = 39;}
//     else if (itemName == "Rabadon's_Deathcap") {returnComboVal = 40;}
//     else if (itemName == "Randuin's_Omen") {returnComboVal = 41;}
//     else if (itemName == "Rapid_Firecannon") {returnComboVal = 42;}
//     else if (itemName == "Ravenous_Hydra") {returnComboVal = 43;}
//     else if (itemName == "Redemption") {returnComboVal = 44;}
//     else if (itemName == "Runaan's_Hurricane") {returnComboVal = 45;}
//     else if (itemName == "Rylai's_Crystal_Scepter") {returnComboVal = 46;}
//     else if (itemName == "Seraph's_Embrace") {returnComboVal = 47;}
//     else if (itemName == "Serpent's_Fang") {returnComboVal = 48;}
//     else if (itemName == "Serylda's_Grudge") {returnComboVal = 49;}
//     else if (itemName == "Silvermere_Dawn") {returnComboVal = 50;}
//     else if (itemName == "Spirit_Visage") {returnComboVal = 51;}
//     else if (itemName == "Staff_of_Flowing_Water") {returnComboVal = 52;}
//     else if (itemName == "Sterak's_Gage") {returnComboVal = 53;}
//     else if (itemName == "Stormrazor") {returnComboVal = 54;}
//     else if (itemName == "The_Collector") {returnComboVal = 55;}
//     else if (itemName == "Thornmail") {returnComboVal = 56;}
//     else if (itemName == "Titanic_Hydra") {returnComboVal = 57;}
//     else if (itemName == "Umbral_Glaive") {returnComboVal = 58;}
//     else if (itemName == "Void_Staff") {returnComboVal = 59;}
//     else if (itemName == "Warmog's_Armor") {returnComboVal = 60;}
//     else if (itemName == "Wit's_End") {returnComboVal = 61;}
//     else if (itemName == "Youmuu's_Ghostblade") {returnComboVal = 62;}
//     else if (itemName == "Zeke's_Convergence") {returnComboVal = 63;}
//     else if (itemName == "Zhonya's_Hourglass") {returnComboVal = 64;}
    

//     return returnComboVal;
// }



//champion/ad/ap/crit/atk/leth/armorPen/omnivamp/lifesteal/abilityHaste/health/mana/armor/mr/healthRegen/manaRegen/apPen