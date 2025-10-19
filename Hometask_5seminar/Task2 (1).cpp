// Hometask vector - PETR SOLDATOV IU1-12B - Task 2

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {-1, 0, 30, 124, -45, 26, 17, 38, -9, 100};
    
    std::for_each(vec.begin(), vec.end(), [](int &n) {
        n = n*2;
    });
    
    for (int n : vec) {
        std::cout << n << " ";
    }
}