// Hometask char - PETR SOLDATOV IU1-12B - Task 4

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    bool lineinline = true;
    for (char c : b) {
        if (a.find(c) == string::npos) {
            lineinline = false;
            break;
        }
    }
    
    cout << (lineinline ? "Да" : "Нет") << endl;
    return 0;
}