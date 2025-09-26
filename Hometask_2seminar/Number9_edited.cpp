// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 9

#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    
    cout << "Enter number n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Type correct positive number " << endl;
        return 1;
    }
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    
    cout << "Sum of numbers divisible by 2 or 5: " << sum << endl;
    return 0;
}