// Hometask char - PETR SOLDATOV IU1-12B - Task 6

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text;
    int shift;
    
    cout << "Текст: ";
    getline(cin, text);
    cout << "Сдвиг: ";
    cin >> shift;
    
    for (char &c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift + 26) % 26 + base;
        }
    }
    
    cout << text << endl;
    return 0;
}