// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 9

#include <iostream>
using namespace std;

int main() {
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    if (number > 0) {
        cout << "Positive number" << endl;
    } 
    if (number < 0) {
        cout << "Negative number" << endl;
    } 
    if (number == 0 ) {
        cout << "Zero" << endl;
    }
    
    return 0;
}