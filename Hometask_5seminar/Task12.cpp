// Hometask vector - PETR SOLDATOV IU1-12B - Task 12

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> fuel_levels;
    for (int i = 0; i < 50; ++i) {
        fuel_levels.push_back(100 - i * 1.5); 
    }
    
    std::cout << "Всего замеров: " << fuel_levels.size() << std::endl;

    double min_level = *std::min_element(fuel_levels.begin(), fuel_levels.end());
    double max_level = *std::max_element(fuel_levels.begin(), fuel_levels.end());
    
    std::cout << "Минимальный уровень: " << min_level << std::endl;
    std::cout << "Максимальный уровень: " << max_level << std::endl;
    
    double threshold = max_level * 0.05;
    bool never_below = std::none_of(fuel_levels.begin(), fuel_levels.end(), [threshold](double level) {
        return level < threshold;
    });
    std::cout << "Никогда не падал ниже 5%: " << (never_below ? "Да" : "Нет") << std::endl;
    
    double total_consumption = fuel_levels.front() - fuel_levels.back();
    double avg_consumption = total_consumption / (fuel_levels.size() - 1);
    std::cout << "Среднее потребление между замерами: " << avg_consumption << std::endl;
    
    std::vector<double> sorted_fuel = fuel_levels;
    std::sort(sorted_fuel.begin(), sorted_fuel.end());
    double median = sorted_fuel.size() % 2 == 0 ? 
        (sorted_fuel[sorted_fuel.size()/2 - 1] + sorted_fuel[sorted_fuel.size()/2]) / 2.0 : 
        sorted_fuel[sorted_fuel.size()/2];
    std::cout << "Медиана: " << median << std::endl;
}