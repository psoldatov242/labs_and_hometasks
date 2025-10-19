// Hometask vector - PETR SOLDATOV IU1-12B - Task 3

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 3, 8, 1, 9, 4, 7, 2, 6, 0};
    auto max_it = std::max_element(vec.begin(), vec.end());
    std::cout << "Максимальный элемент: " << *max_it << std::endl;
}