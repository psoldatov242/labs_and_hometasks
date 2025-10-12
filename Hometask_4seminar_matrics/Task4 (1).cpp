// Hometask matrics - PETR SOLDATOV IU1-12B - Task 4

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    int cnt = 1;
    int l = 0, r = n-1, t = 0, b = n-1;
    
    while (l <= r && t <= b) {
        for (int j = l; j <= r; j++) M[t][j] = cnt++;
        t++;
        for (int i = t; i <= b; i++) M[i][r] = cnt++;
        r--;
        for (int j = r; j >= l; j--) M[b][j] = cnt++;
        b--;
        for (int i = b; i >= t; i--) M[i][l] = cnt++;
        l++;
    }

    for (auto& row : M) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    
    return 0;
}