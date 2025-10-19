// Hometask char - PETR SOLDATOV IU1-12B - Task 7

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    if (s.empty()) {
        cout << "" << endl;
        return 0;
    }
    
    string result;
    char current = s[0];
    int count = 1;
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == current) {
            count++;
        } else {
            result += current + to_string(count);
            current = s[i];
            count = 1;
        }
    }
    result += current + to_string(count);
    
    cout << result << endl;
    return 0;
}