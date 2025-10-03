// Hometask from 3 lesson - PETR SOLDATOV IU1-12B - Task 1

#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    int n;
    cout << "Type quantity of numbers  " << endl;
    cin >> n;

    if (n<=0) {
        cout << "Type positive number of elements" << endl;
        return 1;
    }    
    int posled[n];
    cout << "Введите " << n << " элементов массива. " << endl;

    for (int i = 0; i < n; i++) {
        cout << "Введите " << i << "-й элемент массива:  " << endl;
        cin >> posled[i];
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        double result = pow(2, i);
        if (posled[i] > result) {
            sum +=1;
        }
    }
    cout << "В введенной последовательности чисел " << sum << " чисел удовлетворяют условию n(k) > 2^k" << endl;
}