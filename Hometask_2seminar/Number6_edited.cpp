// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 6

#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Type your age! ";
    cin >> a;
    if (a <= 0 ) {
        cout << "Looks like you are haven`t borned yet " << endl;
    }
    if ((a <= 18) and (a > 0)) {
        cout << "You are 18 or younger" << endl;
    }
    if ((a > 18) and (a < 60)) {
        cout << "You are between 18 and 60 " << endl;
    }
    if (a >= 60) {
        cout << "You are 60 or elder " << endl;
    }
}