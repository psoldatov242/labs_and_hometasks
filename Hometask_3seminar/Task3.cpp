// Hometask from 3 lesson - PETR SOLDATOV IU1-12B - Task 3

#include <iostream>
using namespace std;

int main() {
    cout << "Type 15 numbers to replace some of them " << endl;
    double array[15];
    for (int i = 0; i < 15; i++) {
        cout << "Type " << (i+1) << " number of array" << endl;
        cin >> array[i];
    }
    
    int min_index = 0;
    int max_index = 0;
    
    for (int j = 1; j < 15; j++) {
        if (array[j] < array[min_index]) {
            min_index = j;
        }
        if (array[j] > array[max_index]) {
            max_index = j;
        }
    }
    
    cout << "Min element: " << array[min_index] << " at position " << min_index << endl;
    cout << "Max element: " << array[max_index] << " at position " << max_index << endl;
    
    double temp = array[0];
    array[0] = array[min_index];
    array[min_index] = temp;
    
    if (max_index == 0) {
        max_index = min_index;
    }
    
    temp = array[14];
    array[14] = array[max_index];
    array[max_index] = temp;
    
    cout << "Array after replacement:" << endl;
    for (int i = 0; i < 15; i++) {
        cout << "Element " << i << ": " << array[i] << endl;
    }
    
    return 0;
}