// Hometask Geometry - PETR SOLDATOV IU1-12B - Task 5

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    
    cout << "Введите координаты первой точки (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты второй точки (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Введите координаты третьей точки (x3 y3): ";
    cin >> x3 >> y3;
    
    double result = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    
    if (result == 0) {
        cout << "Точки лежат на одной прямой" << endl;
    } else {
        cout << "Точки НЕ лежат на одной прямой" << endl;
    }
    
    return 0;
}