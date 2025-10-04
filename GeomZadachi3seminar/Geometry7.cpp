// Hometask Geometry - PETR SOLDATOV IU1-12B - Task 7

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Введите количество вершин многоугольника: ";
    cin >> n;
    
    vector<double> x(n), y(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i+1 << " (x y): ";
        cin >> x[i] >> y[i];
    }
    
    double px, py;
    cout << "Введите координаты точки (x y): ";
    cin >> px >> py;
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        
        if ((y[i] > py) != (y[j] > py)) {
            double intersect_x = (x[j] - x[i]) * (py - y[i]) / (y[j] - y[i]) + x[i];
            if (px < intersect_x) {
                count++;
            }
        }
    }
    
    if (count % 2 == 1) {
        cout << "Точка находится внутри нашего многоугольника" << endl;
    } else {
        cout << "Точка находится снаружи нашего многоугольника" << endl;
    }
    
    return 0;
}