// Hometask from 3 lesson - PETR SOLDATOV IU1-12B - Task 8

#include <iostream>
using namespace std;

int main() {
    cout << "Type 10 numbers: " << endl;
    int array[10];
    
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
    
    if ((max_index == 1) && (min_index == 4)) {
        for (int i = min_index; i < 10; i++) {
            array[i] = array[max_index];
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << array[i] << endl;
    }
    
    return 0;
}