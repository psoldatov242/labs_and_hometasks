// Hometask matrics - PETR SOLDATOV IU1-12B - Task 3
//По подсказке через подсчет мин и макс в строке и столбце
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    vector<int> row_min(n, INT_MAX), row_max(n, INT_MIN);
    vector<int> col_min(m, INT_MAX), col_max(m, INT_MIN);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row_min[i] = min(row_min[i], A[i][j]);
            row_max[i] = max(row_max[i], A[i][j]);
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            col_min[j] = min(col_min[j], A[i][j]);
            col_max[j] = max(col_max[j], A[i][j]);
        }
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == row_min[i] && A[i][j] == col_max[j]) {
                cout << "A " << A[i][j] << " " << i+1 << " " << j+1 << endl;
                found = true;
            }
            if (A[i][j] == row_max[i] && A[i][j] == col_min[j]) {
                cout << "B " << A[i][j] << " " << i+1 << " " << j+1 << endl;
                found = true;
            }
        }
    }
    if (!found) cout << "NONE" << endl;
    
    return 0;
}