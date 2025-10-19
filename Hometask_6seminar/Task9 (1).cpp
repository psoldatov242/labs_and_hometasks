// Hometask char - PETR SOLDATOV IU1-12B - Task 9

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    int maxLen = 0;
    string result;
    
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            int len = 0;
            while (i + len < s1.length() && 
                   j + len < s2.length() && 
                   s1[i + len] == s2[j + len]) {
                len++;
            }
            if (len > maxLen) {
                maxLen = len;
                result = s1.substr(i, len);
            }
        }
    }
    
    cout << result << endl;
    return 0;
}