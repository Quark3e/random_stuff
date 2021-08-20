#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    bool loopVal = true;
    int randomNum, Guess;
    int options;
    while(loopVal) {

    srand (time(NULL));

    randomNum = rand() % 10 + 1;

    while(randomNum != Guess) {
        cout << "Guess random number (1 to 10): ";
        cin >> Guess;
        if (randomNum<Guess) {cout << "\nThe secret number is lower\n";}
        else if (randomNum>Guess) {cout << "\nThe secret number is higher\n";}
    }

    cout << "\nCorrect answer\n";

    cout << "Want to 1.Repeat or 2. Exit? ";
    cin >> options;

    if(options == 2) {loopVal = false;}
    }

    return 0;
}