// Hometask matrics - PETR SOLDATOV IU1-12B - Task 8
// Просто задачи 6-8 по Крамеру

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double det2(double a, double b, double c, double d) {
    return a*d - b*c;
}

double det3(vector<vector<double>> M) {
    return M[0][0] * det2(M[1][1], M[1][2], M[2][1], M[2][2])
         - M[0][1] * det2(M[1][0], M[1][2], M[2][0], M[2][2])
         + M[0][2] * det2(M[1][0], M[1][1], M[2][0], M[2][1]);
}

int main() {
    // Система:
    // 3x - y + 2z = 5
    // 2x + 4y - z = 6
    // x - 3y + z = 4
    
    vector<vector<double>> M = {
        {3, -1, 2},
        {2, 4, -1},
        {1, -3, 1}
    };
    vector<double> B = {5, 6, 4};
    
    double D = det3(M);
    if (fabs(D) < 1e-9) {
        cout << "Система не имеет единственного решения" << endl;
        return 0;
    }
    
    vector<vector<double>> Mx = M, My = M, Mz = M;
    for (int i = 0; i < 3; i++) {
        Mx[i][0] = B[i];
        My[i][1] = B[i];
        Mz[i][2] = B[i];
    }
    
    double Dx = det3(Mx);
    double Dy = det3(My);
    double Dz = det3(Mz);
    
    cout << "x = " << Dx/D << ", y = " << Dy/D << ", z = " << Dz/D << endl;
    
    return 0;
}