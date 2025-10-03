// Hometask from 3 lesson - PETR SOLDATOV IU1-12B - Task 6

#include <iostream>
using namespace std;

int main() {
    cout << "Type 15 numbers: " << endl;
    double array[15];
    
    for (int i = 0; i < 15; i++) {
        cout << "Type " << (i+1) << " number: ";
        cin >> array[i];
    }
    
    int min_index = 0;
    int max_index = 0;
    
    for (int i = 1; i < 15; i++) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
        if (array[i] > array[max_index]) {
            max_index = i;
        }
    }
    
    cout << "Min element: " << array[min_index] << " at position " << min_index << endl;
    cout << "Max element: " << array[max_index] << " at position " << max_index << endl;
    
    if (min_index == 1 && max_index == 0) {
        for (int i = 0; i < 15; i++) {
            array[i] = array[i]/2;
        }
    }
    for (int i = 0; i < 15; i++) {
        cout << array[i] << endl;
    }
    
    return 0;
}