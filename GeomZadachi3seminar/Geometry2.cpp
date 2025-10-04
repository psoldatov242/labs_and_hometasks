// Hometask Geometry - PETR SOLDATOV IU1-12B - Task 2

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Введите количество вершин многоугольника: ";
    cin >> n;
    
    vector<double> x(n), y(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Введите координаты вершины " << i+1 << " (x y): ";
        cin >> x[i] >> y[i];
    }
    
    double perimeter = 0.0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        double dx = x[next] - x[i];
        double dy = y[next] - y[i];
        perimeter += sqrt(dx*dx + dy*dy);
    }
    
    cout << "Периметр многоугольника: " << perimeter << endl;
    
    return 0;
}