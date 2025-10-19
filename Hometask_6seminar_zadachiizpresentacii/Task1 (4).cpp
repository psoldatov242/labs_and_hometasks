// Hometask char from presentacia - PETR SOLDATOV IU1-12B - Task 1

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1000];
    cin.getline(str, 1000);
    
    int maxLen = 0;
    char longestWord[100] = "";
    char currentWord[100] = "";
    
    int len = strlen(str);
    int wordStart = 0;
    
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            int wordLen = i - wordStart;
            
            if (wordLen > 0) {
                strncpy(currentWord, str + wordStart, wordLen);
                currentWord[wordLen] = '\0';
                
                if (wordLen > maxLen) {
                    maxLen = wordLen;
                    strcpy(longestWord, currentWord);
                }
            }
            wordStart = i + 1;
        }
    }
    
    cout << longestWord << endl;
    return 0;
}