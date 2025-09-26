// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 4

#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Type number to check it`s odd or even " << endl;
    cin >> a;
    if (a % 2 == 0) {
        cout << "Even number!" << endl;
    } else {
        cout << "Odd number!" << endl;
    }
}