// Hometask char - PETR SOLDATOV IU1-12B - Task 8

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    bool newSentence = true;
    for (int i = 0; i < s.length(); i++) {
        if (newSentence && isalpha(s[i])) {
            s[i] = toupper(s[i]);
            newSentence = false;
        } else if (isalpha(s[i])) {
            s[i] = tolower(s[i]);
        }
        
        if (s[i] == '.' || s[i] == '!' || s[i] == '?') {
            newSentence = true;
        }
    }
    
    cout << s << endl;
    return 0;
}