// Hometask matrics - PETR SOLDATOV IU1-12B - Task 6
// Просто задачи 6-8 по Крамеру

#include <iostream>
#include <cmath>
using namespace std;

double det2(double a, double b, double c, double d) {
    return a*d - b*c;
}

int main() {
    // Система: 
    // 2x + 3y = 13
    // 5x - y = 9
    double a1 = 2, b1 = 3, c1 = 13;
    double a2 = 5, b2 = -1, c2 = 9;
    
    double D = det2(a1, b1, a2, b2);
    double Dx = det2(c1, b1, c2, b2);
    double Dy = det2(a1, c1, a2, c2);
    
    if (fabs(D) < 1e-9) {
        cout << "Система не имеет единственного решения" << endl;
    } else {
        cout << "x = " << Dx/D << ", y = " << Dy/D << endl;
        //Proverka
        cout << 2*(Dx/D) + 3*(Dy/D) << endl;
        cout << 5*(Dx/D) - (Dy/D) << endl;
    }
    
    return 0;
}