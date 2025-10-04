// Hometask Geometry - PETR SOLDATOV IU1-12B - Task 8

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    
    cout << "Введите координаты первой точки (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты второй точки (x2 y2): ";
    cin >> x2 >> y2;
    
    double dx = x2 - x1;
    double dy = y2 - y1;
    double length = sqrt(dx*dx + dy*dy);
    
    cout << "Длина отрезка: " << length << endl;
    
    return 0;
}