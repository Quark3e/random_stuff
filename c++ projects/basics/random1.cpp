#include <iostream>

using namespace std;

int baboon(int input);

int main() {
    int chineseFighter;

    cin >> chineseFighter;

    cout << baboon(chineseFighter) << endl;

    system("pause");
    return 0;
}

int baboon(int input) {   

    int returnValue = input * 4;
    return returnValue;
}