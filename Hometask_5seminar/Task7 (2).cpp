// Hometask vector - PETR SOLDATOV IU1-12B - Task 7

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> temps = {-15.5, 25.0, 30.2, -60.0, 40.7, 55.5, -10.0};
    
    temps.erase(std::remove_if(temps.begin(), temps.end(), [](double t) {
        return (t < -50) or (t > 50);
    }), temps.end());
    
    double min_temp = *std::min_element(temps.begin(), temps.end());
    double max_temp = *std::max_element(temps.begin(), temps.end());
    
    double sum = 0;
    std::for_each(temps.begin(), temps.end(), [&sum](double t) {
        sum += t;
    });
    double avg_temp = sum / temps.size();
    
    std::cout << "Мин: " << min_temp << " Макс: " << max_temp << " Среднее: " << avg_temp << std::endl;
    
    bool all_above = std::all_of(temps.begin(), temps.end(), [](double t) {
        return t > -10;
    });
    std::cout << "Все выше -10: " << (all_above ? "Да" : "Нет") << std::endl;
}