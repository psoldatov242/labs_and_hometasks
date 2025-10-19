// Hometask char - PETR SOLDATOV IU1-12B - Task 5

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    int vowels = 0, consonants = 0;
    string vowelChars = "aeiouy";
    
    for (char c : s) {
        if (isalpha(c)) {
            char lowerC = tolower(c);
            if (vowelChars.find(lowerC) != string::npos) {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    cout << "Гласных: " << vowels << endl;
    cout << "Согласных: " << consonants << endl;
}