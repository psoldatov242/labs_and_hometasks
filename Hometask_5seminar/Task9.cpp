// Hometask vector - PETR SOLDATOV IU1-12B - Task 9

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> powers = {15.5, -2.0, 88.0, 95.5, -1.2, 75.0, 10.2, 5.0, 100.0, 90.0, 31.5, 40.5, 31.5, 50.5, -4.0, -5.0, 40.0, 60.5, 91.5, 30.5};
    
    powers.erase(std::remove_if(powers.begin(), powers.end(), [](double p) {
        return p < 0;
    }), powers.end());
    
    double min_power = *std::min_element(powers.begin(), powers.end());
    double max_power = *std::max_element(powers.begin(), powers.end());
    
    double sum = 0;
    std::for_each(powers.begin(), powers.end(), [&sum](double p) {
        sum += p;
    });
    double avg_power = sum / powers.size();
    
    std::cout << "Мин: " << min_power << " Макс: " << max_power << " Среднее: " << avg_power << std::endl;
    
    bool in_range = std::all_of(powers.begin(), powers.end(), [](double p) {
        return p >= 10 && p <= 90;
    });
    std::cout << "Работал в диапазоне 10-90: " << (in_range ? "Да" : "Нет") << std::endl;
    
    std::sort(powers.begin(), powers.end());
    double median = powers.size() % 2 == 0 ? 
        (powers[powers.size()/2 - 1] + powers[powers.size()/2]) / 2.0 : 
        powers[powers.size()/2];
    std::cout << "Медиана: " << median << std::endl;
}