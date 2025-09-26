// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 5 (Для отрицательны чисел тоже корректно)

#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter a number to see if it is divisible by 3 and 5! " << endl;
    cin >> a;
    if ((a % 3 == 0) and (a % 5 != 0)) {
        cout << "The number is only divisible by 3, but not by 5 " << endl;
    }

    if ((a % 3 != 0) and (a % 5 == 0)) {
        cout << "The number is only divisible by 5, but not for 3 " << endl;
    }

    if ((a % 3 == 0) and (a % 5 == 0)) {
        cout << "The nubmer is divisible by 3 and 5 " << endl;
    }

    if ((a % 3 != 0) and (a % 5 != 0)) {
        cout << "The number isn`t divisible by 3 or 5 " << endl;
    }
}