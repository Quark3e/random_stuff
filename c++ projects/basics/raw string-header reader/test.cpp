#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "raw_string_container.h"
using namespace std;



int main() {
    string option;

    cout << "Want to read the raw string?\n";
    cout << "Yes No:";
    cin >> option;

    if (option == "Yes") {
        cout << dataFile;
    }
    else if (option == "No") {
        cout << "well fuck you here's it anyway:\n" << dataFile;
    }
    else {cout << "tf you writing";}

    system("pause");

}
