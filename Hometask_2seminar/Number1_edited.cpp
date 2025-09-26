// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 1

#include <iostream>
using namespace std;

int main() {
    long long int a,b,c;
    cout << "Type length in cm: " << endl;
    cin >> a;
    if (a < 0) {
       cout << "Error: length cannot be negative!" << endl;
       return 1;
   }
    b = a / 100;
    c = a % 100;
    cout << "That`s " << b << " meters and " << c << " cm" << endl;

}