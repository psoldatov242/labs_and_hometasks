// Hometask Geometry - PETR SOLDATOV IU1-12B - Task 9

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n1, n2;
    
    cout << "Введите количество вершин первого многоугольника: ";
    cin >> n1;
    vector<double> x1(n1), y1(n1);
    for (int i = 0; i < n1; i++) {
        cout << "Вершина " << i+1 << " (x y): ";
        cin >> x1[i] >> y1[i];
    }
    
    cout << "Введите количество вершин второго многоугольника: ";
    cin >> n2;
    vector<double> x2(n2), y2(n2);
    for (int i = 0; i < n2; i++) {
        cout << "Вершина " << i+1 << " (x y): ";
        cin >> x2[i] >> y2[i];
    }
    
    bool peresechenie = false;
    
    for (int i = 0; i < n1; i++) {
        int next_i = (i + 1) % n1;
        for (int j = 0; j < n2; j++) {
            int next_j = (j + 1) % n2;
            
            double xa = x1[i], ya = y1[i];
            double xb = x1[next_i], yb = y1[next_i];
            double xc = x2[j], yc = y2[j];
            double xd = x2[next_j], yd = y2[next_j];
            
            double cp1 = (xb - xa) * (yc - ya) - (yb - ya) * (xc - xa);
            double cp2 = (xb - xa) * (yd - ya) - (yb - ya) * (xd - xa);
            double cp3 = (xd - xc) * (ya - yc) - (yd - yc) * (xa - xc);
            double cp4 = (xd - xc) * (yb - yc) - (yd - yc) * (xb - xc);
            
            if ((cp1 * cp2 < 0) && (cp3 * cp4 < 0)) {
                peresechenie = true;
                break;
            }
        }
        if (peresechenie) break;
    }
    
    if (peresechenie) {
        cout << "Многоугольники пересекаются!" << endl;
    } else {
        cout << "Многоугольники не пересекаются!" << endl;
    }
    
    return 0;
}