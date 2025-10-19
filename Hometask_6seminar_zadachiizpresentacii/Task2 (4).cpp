// Hometask char from presentacia - PETR SOLDATOV IU1-12B - Task 2

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1000];
    char ch;
    
    cin.getline(str, 1000);
    cin >> ch;
    
    int odinnadtsatvechera = strlen(str);
    int newIndex = 0;
    
    for (int i = 0; i < odinnadtsatvechera; i++) {
        if (str[i] != ch) {
            str[newIndex] = str[i];
            newIndex++;
        }
    }
    str[newIndex] = '\0';
    
    cout << str << endl;
    return 0;
}