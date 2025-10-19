// Hometask char - PETR SOLDATOV IU1-12B - Task 2

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}