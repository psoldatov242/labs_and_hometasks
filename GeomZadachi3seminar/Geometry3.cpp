// Hometask Geometry - PETR SOLDATOV IU1-12B - Task 3

#include <iostream>
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    
    cout << "Введите координаты первой вершины (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты второй вершины (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Введите координаты третьей вершины (x3 y3): ";
    cin >> x3 >> y3;
    
    double center_x = (x1 + x2 + x3) / 3.0;
    double center_y = (y1 + y2 + y3) / 3.0;
    
    cout << "Центр масс треугольника: (" << center_x << ", " << center_y << ")" << endl;
    
    return 0;
}