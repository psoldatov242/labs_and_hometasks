// Hometask char from presentacia - PETR SOLDATOV IU1-12B - Task 4

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1000];
    cin.getline(str, 1000);
    
    int len = strlen(str);
    int slova = 0;
    bool inWord = false;
    
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0') {
            if (inWord) {
                for (int j = slova; j < i; j++) {
                    cout << str[j];
                }
                cout << endl;
                inWord = false;
            }
        } else {
            if (!inWord) {
                slova = i;
                inWord = true;
            }
        }
    }
}