// Hometask char from presentacia - PETR SOLDATOV IU1-12B - Task 3

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1000], oldSub[100], newSub[100];
    char result[2000] = "";
    
    cin.getline(str, 1000);
    cin.getline(oldSub, 100);
    cin.getline(newSub, 100);
    
    int strLen = strlen(str);
    int oldLen = strlen(oldSub);
    int newLen = strlen(newSub);
    int i = 0;
    while (i < strLen) {
        bool found = true;
        
        for (int j = 0; j < oldLen; j++) {
            if (str[i + j] != oldSub[j]) {
                found = false;
                break;
            }
        }
        
        if (found) {
            strcat(result, newSub);
            i += oldLen;
        } else {
            int len = strlen(result);
            result[len] = str[i];
            result[len + 1] = '\0';
            i++;
        }
    }
    
    cout << result << endl;
    return 0;
}