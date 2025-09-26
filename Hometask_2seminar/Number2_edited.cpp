// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 2

#include <iostream>
using namespace std;

int main() {
    double a,b,c;
    cout << "Type length: " << endl;
    cin >> a;
    cout << "Type width " << endl;
    cin >> b;
    if (a < 0 || b < 0) {
       cout << "Error: length and width cannot be negative!" << endl;
       return 1;
   } else {
        c = a * b;
    cout << "Area equals: " << c << endl; 
   }
}