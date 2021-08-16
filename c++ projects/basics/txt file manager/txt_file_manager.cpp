#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void createFile(string Name);
void writeToFile(string Name);
void readFromFile(string Name);
void choiceFunction();

bool loopVal;

int main() {
    loopVal = true;

    choiceFunction();

    cout << "\n";
    return 0;
}

void createFile(string Name) {
    string Title = "textFile.txt";
    Title = (Name + ".txt");
    ofstream txtFile(Title);
    cout << Title << " created.\n";
}

void writeToFile(string Name) {
    string textToWrite;
    ofstream txtFile(Name);
    if (txtFile.fail()) {
        cout << "Error lol: the file does not exist.\n";
    }
    else {
        cout << "Enter text to send: ";
        cin >> textToWrite;
        txtFile << textToWrite;
        txtFile.close();
        cout << "\n Text sent.";
    }
}

void readFromFile(string Name) {
    string myText;
    ifstream txtFile(Name);
    if (txtFile.fail()) {
        cout << "Error lol: the file does not exist.\n";
    }
    else {
        while (getline(txtFile, myText)) {
            cout << myText << "\n";
        }
        cout << "finished.\n";
        system("pause");
    }
    txtFile.close();
}

void choiceFunction() {
    string Name;
    string EditText;
    string fileName;
    int op;
    while(loopVal) {
        cout << "Want to 1.create, 2.edit, 3.read txt file or 4.Exit? \n";
        cout << "option: ";
        cin >> op;

        switch(op) {
            case 1:
                cout << "Enter file name: ";
                cin >> Name;
                createFile(Name);
             break;
            case 2:
                cout << "Enter file name: ";
                cin >> fileName;
                writeToFile(fileName);
                break;
            case 3:
                cout << "Enter file name: ";
                cin >> fileName;
                readFromFile(fileName);
                break;
            case 4:
                cout << "exiting. . .";
                loopVal = false;
                break;
            default:
                cout << op << " is an invalid answer";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
    }
}
