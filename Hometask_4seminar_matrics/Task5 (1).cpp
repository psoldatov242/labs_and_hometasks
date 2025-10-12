// Hometask matrics - PETR SOLDATOV IU1-12B - Task 5

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    int l = 0, r = m-1, t = 0, b = n-1;
    while (l <= r && t <= b) {
        for (int j = l; j <= r; j++) cout << A[t][j] << " ";
        t++;
        for (int i = t; i <= b; i++) cout << A[i][r] << " ";
        r--;
        if (t <= b) {
            for (int j = r; j >= l; j--) cout << A[b][j] << " ";
            b--;
        }
        if (l <= r) {
            for (int i = b; i >= t; i--) cout << A[i][l] << " ";
            l++;
        }
    }
    cout << endl;
    
    return 0;
}