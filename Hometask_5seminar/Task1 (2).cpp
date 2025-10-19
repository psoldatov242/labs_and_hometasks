// Hometask vector - PETR SOLDATOV IU1-12B - Task 1

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, -41, 30, 32, 44, 6, -9, -3, -1, 10};
    
    std::for_each(vec.begin(), vec.end(), [](int n) {
        std::cout << n << " ";
    });
}