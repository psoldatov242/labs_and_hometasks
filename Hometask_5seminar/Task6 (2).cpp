// Hometask vector - PETR SOLDATOV IU1-12B - Task 6

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 8, 2, 9, 3, 7, 6, 7, 12, 64, 32, 44, 53, 21, 98, 32, 43, 33, 11, 11};

    bool ESTbli7 = std::find(vec.begin(), vec.end(), 7) != vec.end();
    std::cout << "Есть ли 7: " << (ESTbli7 ? "Да" : "Нет") << std::endl;
    
    std::sort(vec.begin(), vec.end());
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
    
    std::cout << "Уникальные элементы: ";
    std::for_each(vec.begin(), vec.end(), [](int n) {
        std::cout << n << " ";
    });
}