// Hometask matrics - PETR SOLDATOV IU1-12B - Task 2
//Равенство сумм без проверки набра чисел
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

    int sum = 0;
    for (int j = 0; j < n; j++) sum += A[0][j];

    // Проверка строк
    for (int i = 1; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) s += A[i][j];
        if (s != sum) { cout << "NO" << endl; return 0; }
    }

    // Проверка столбцов
    for (int j = 0; j < n; j++) {
        int s = 0;
        for (int i = 0; i < n; i++) s += A[i][j];
        if (s != sum) { cout << "NO" << endl; return 0; }
    }

    // Главная диагональ
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) s1 += A[i][i];
    for (int i = 0; i < n; i++) s2 += A[i][n-1-i];
    
    if (s1 == sum && s2 == sum) cout << "YES " << sum << endl;
    else cout << "NO" << endl;
    
    return 0;
}