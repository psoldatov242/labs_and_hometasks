// Hometask vector - PETR SOLDATOV IU1-12B - Task 8

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> speeds = {45, 80, 130, 65, 140, 95, 110, 125, 70, 85, 0, 150, 30, 10, 110, 160};
    
    speeds.erase(std::remove_if(speeds.begin(), speeds.end(), [](int s) {
        return s > 120;
    }), speeds.end());
    
    double sum = 0;
    std::for_each(speeds.begin(), speeds.end(), [&sum](int s) {
        sum += s;
    });
    double avg = sum / speeds.size();
    std::cout << "Средняя скорость: " << avg << std::endl;
    
    bool always_moving = std::all_of(speeds.begin(), speeds.end(), [](int s) {
        return s > 0;
    });
    std::cout << "Всегда двигался: " << (always_moving ? "Да" : "Нет") << std::endl;
    
    std::sort(speeds.begin(), speeds.end(), [](int a, int b) {
        return a > b; 
    });
    std::cout << "Топ-10 скоростей: ";
    int count = std::min(10, (int)speeds.size());
    std::for_each(speeds.begin(), speeds.begin() + count, [](int s) {
        std::cout << s << " ";
    });
}