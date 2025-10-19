// Hometask vector - PETR SOLDATOV IU1-12B - Task 10

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> energy = {150, 200, 180, 220, 190, 210, 170, 300, 250, 320, 75, 444, 760, 333, 963, 322, 100, 543, 300, 322, 22, 100, 400, 200, 250, 300, 300, 100, 150};
    
    double total = 0;
    std::for_each(energy.begin(), energy.end(), [&total](double e) {
        total += e;
    });
    std::cout << "Общее потребление: " << total << std::endl;
    
    double avg = total / energy.size();
    std::cout << "Среднее: " << avg << std::endl;
    
    auto min_it = std::min_element(energy.begin(), energy.end());
    auto max_it = std::max_element(energy.begin(), energy.end());
    std::cout << "Мин день: " << *min_it << " Макс день: " << *max_it << std::endl;
    
    std::cout << "Пиковые дни: ";
    std::for_each(energy.begin(), energy.end(), [avg](double day) {
        if (day > avg * 1.2) {
            std::cout << day << " ";
        }
    });
}