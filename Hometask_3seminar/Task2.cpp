// Hometask from 3 lesson - PETR SOLDATOV IU1-12B - Task 2

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cout << "Type quantity of numbers: " << endl;
    cin >> n;

    if (n <= 0) {
        cout << "Type positive number of elements" << endl;
        return 1;
    }    
    int posled[n];
    cout << "Введите " << n << " элементов массива: " << endl;

    for (int i = 0; i < n; i++) {
        cout << "Введите " << i << "-й элемент массива: ";
        cin >> posled[i];
    }

    int k;
    cout << "Now type amount of numbers to compare with: ";
    cin >> k;
    
    cout << "Now type numbers to compare with numbers before, one number in one line" << endl;
    int amountchet = 0;
    int maxnechet = 0;
    bool foundOdd = false; 

    for (int j = 0; j < k; j++) {
        int currentnumber;
        cout << "Number " << (j + 1) << ": ";
        cin >> currentnumber;

        bool numberFound = false;
        for (int i = 0; i < n; i++) {
            if (posled[i] == currentnumber) {
                numberFound = true;
                break;
            }
        }

        if (numberFound) {
            if (currentnumber % 2 == 0) {
                amountchet += 1;
            }
            if ((currentnumber > maxnechet) && (currentnumber % 2 != 0)) { 
                maxnechet = currentnumber;
                foundOdd = true;
            }
        }
    }
    
    cout << amountchet << " numbers are even and contained in array" << endl;
    
    if (foundOdd) {
        cout << "Max odd number in array is " << maxnechet << endl;
    } else {
        cout << "No odd numbers found in array" << endl;
    }
    
    return 0;
}