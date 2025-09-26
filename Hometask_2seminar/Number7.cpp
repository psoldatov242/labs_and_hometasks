// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 7

#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter a number " << endl;
    cin >> a;

    if (a <= 0) {
        cout << "Please enter a positive number greater than 0 " << endl;
        return 1;
    }
    
    cout << "Table of squares from 1 to your number: " << endl;

    for (int i = 1; i <= a; i++) {
        cout << "Number: " << i << ", square is " << i * i << endl;
    }
}