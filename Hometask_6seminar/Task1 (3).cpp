// Hometask char - PETR SOLDATOV IU1-12B - Task 1

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    string cleaned;
    for (char c : s) {
        if (!isspace(c)) {
            cleaned += tolower(c);
        }
    }
    
    bool Palindrom = true;
    int len = cleaned.length();
    for (int i = 0; i < len / 2; i++) {
        if (cleaned[i] != cleaned[len - 1 - i]) {
            Palindrom = false;
            break;
        }
    }
    
    cout << (Palindrom ? "Палиндром" : "Не палиндром") << endl;
}