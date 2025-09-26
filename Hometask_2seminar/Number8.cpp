// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 8

#include <iostream>
using namespace std;

int main() {
    char c;
    int vowelCount = 0;
    
    cout << "Enter characters one by one (type '.' to finish): " << endl;
    
    
    while (true) {
        cin >> c; 
        
        if (c == '.') { 
            break;
        }
        
        
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowelCount++;
        }
    }
    
    cout << "Number of vowels: " << vowelCount << endl;
    return 0;
}