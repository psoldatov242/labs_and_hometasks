// Hometask char - PETR SOLDATOV IU1-12B - Task 3

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    string result;
    for (char c : s) {
        if (!isdigit(c)) {
            result += c;
        }
    }
    cout << "Результат без цифр:" << endl;
    cout << result << endl;
}