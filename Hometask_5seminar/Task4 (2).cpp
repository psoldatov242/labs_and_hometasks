// Hometask vector - PETR SOLDATOV IU1-12B - Task 4

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, -2, 8, -1, 9, -3, 7, 4, -6, 0};
    
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) {
        return x < 0;
    }), vec.end());
    
    for (int n : vec) {
        std::cout << n << " ";
    }
}