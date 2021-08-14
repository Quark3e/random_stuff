#include <iostream>
using namespace std;

int n;
int byteVar;
string arrayVar[10];
string switchCaseFunction(int var1, int i);

int main() {
  cout << "Hello World!\n";
  byteVar = 3;
  n = 3;
  arrayVar[n] = switchCaseFunction(byteVar, n);
  cout << arrayVar[n];
  
  return 0;
}

string switchCaseFunction(int var1, int i) {
  string temporaryVar;
  switch (var1) {
    case 1:
    	temporaryVar = "Bird";
    	break;
    case 2:
    	temporaryVar = "Dog";
    	break;
    default:
        cout << "Nothing. Nada, niet\n";
        temporaryVar = "null";
  }
  return temporaryVar;
}



