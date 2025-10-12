// Hometask matrics - PETR SOLDATOV IU1-12B - Task 1

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    // 1. Главная диагональ (транспонирование)
    vector<vector<int>> main_diag(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            main_diag[i][j] = A[j][i];

    // 2. Побочная диагональ
    vector<vector<int>> side_diag(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            side_diag[i][j] = A[n-1-j][n-1-i];

    // 3. Вертикальное отражение
    vector<vector<int>> vertical(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            vertical[i][j] = A[i][n-1-j];

    // 4. Горизонтальное отражение
    vector<vector<int>> horizontal(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            horizontal[i][j] = A[n-1-i][j];

    // Вывод матриц
    cout << "Транспонирование " << endl;
    for (auto& row : main_diag) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    cout << "Главная диагональ " << endl;
    for (auto& row : side_diag) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    cout << "Вертикальное отражение"  << endl;
    for (auto& row : vertical) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    cout << "Горизонтальное отражение " << endl;
    for (auto& row : horizontal) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    // Сравнение пар
    vector<vector<int>> mats[4] = {main_diag, side_diag, vertical, horizontal};
    bool found = false;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            if (mats[i] == mats[j]) {
                cout << i+1 << " " << j+1 << endl;
                found = true;
            }
        }
    }
    if (!found) cout << "NONE (совпадений нет)" << endl;
    
    return 0;
}