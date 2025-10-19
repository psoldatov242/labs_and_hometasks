// Hometask char - PETR SOLDATOV IU1-12B - Task 11

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    for (int i = 0; i <= (int)s.length() - k; i++) {
        string substr = s.substr(i, k);
        bool allUnique = true;
        for (int j = 0; j < k && allUnique; j++) {
            for (int m = j + 1; m < k; m++) {
                if (substr[j] == substr[m]) {
                    allUnique = false;
                    break;
                }
            }
        }
        if (allUnique) {
            cout << substr << endl;
        }
    }
    return 0;
}