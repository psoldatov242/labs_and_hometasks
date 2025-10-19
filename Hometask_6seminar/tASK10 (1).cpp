// Hometask char - PETR SOLDATOV IU1-12B - Task 10

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    size_t start = 0;
    for (size_t i = 0; i <= s.length(); i++) {
        if (i == s.length() || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    
    cout << s << endl;
    return 0;
}