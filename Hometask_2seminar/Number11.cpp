// Hometask from 2 lesson - PETR SOLDATOV IU1-12B - Task 9

#include <iostream>
using namespace std;

int main() {
    cout << "ASCII Table (32-126):" << endl;
    cout << "Code | Character" << endl;
    cout << "-----|----------" << endl;
    
    for (int i = 32; i <= 126; i++) {
        cout << "  " << i << "  |    '" << (char)i << "'" << endl;
    }
    
    return 0;
}