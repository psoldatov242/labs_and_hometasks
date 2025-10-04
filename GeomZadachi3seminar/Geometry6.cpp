// Hometask Geometry - PETR SOLDATOV IU1-12B - Task 6

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    cout << "Введите координаты первого отрезка:" << endl;
    cout << "Начало (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Конец (x2 y2): ";
    cin >> x2 >> y2;
    
    cout << "Введите координаты второго отрезка:" << endl;
    cout << "Начало (x3 y3): ";
    cin >> x3 >> y3;
    cout << "Конец (x4 y4): ";
    cin >> x4 >> y4;
    
    double cp1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    double cp2 = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);
    double cp3 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
    double cp4 = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3);
    
    bool peresechenie = (cp1 * cp2 < 0) && (cp3 * cp4 < 0);
    
    if (peresechenie) {
        cout << "Пересекаются!" << endl;
    }

    if (not(peresechenie)) {
        cout << "Не пересекаются!" << endl;
    }
    
    return 0;
}