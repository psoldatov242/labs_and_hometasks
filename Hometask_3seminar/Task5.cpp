// Hometask from 3 lesson - PETR SOLDATOV IU1-12B - Task 5

#include <iostream>
using namespace std;

int main() {
    cout << "Type 10 numbers: " << endl;
    double array[10];
    
    for (int i = 0; i < 10; i++) {
        cout << "Type " << (i+1) << " number: ";
        cin >> array[i];
    }
    
    int min_index = 0;
    int max_index = 0;
    
    for (int i = 1; i < 10; i++) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
        if (array[i] > array[max_index]) {
            max_index = i;
        }
    }
    
    cout << "Min element: " << array[min_index] << " at position " << min_index << endl;
    cout << "Max element: " << array[max_index] << " at position " << max_index << endl;
    
    if (min_index == 4 && max_index == 9) {
        double product = (array[max_index] + array[min_index])/2;
        cout << "Condition is fulfilled, average is " << product << endl;
    } else {
        cout << "Condition isn`t fulfilled. Result not exist" << endl;
    }
    
    return 0;
}