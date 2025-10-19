// Hometask vector - PETR SOLDATOV IU1-12B - Task 13

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> pressures;
    for (int i = 0; i < 50; ++i) {
        pressures.push_back(5.0 + (i % 15) * 0.5); 
    }
    pressures[10] = -1.0;
    pressures[25] = 15.0;
    pressures[40] = -2.5;
    
    std::cout << "Всего измерений: " << pressures.size() << std::endl;
    
    pressures.erase(std::remove_if(pressures.begin(), pressures.end(), [](double p) {
        return p < 0 || p > 12;
    }), pressures.end());
    
    std::cout << "После удаления ошибок осталось: " << pressures.size() << " измерений" << std::endl;
    
    double sum = 0;
    std::for_each(pressures.begin(), pressures.end(), [&sum](double p) {
        sum += p;
    });
    double avg_pressure = sum / pressures.size();
    std::cout << "Среднее давление: " << avg_pressure << std::endl;
    
    auto minmax = std::minmax_element(pressures.begin(), pressures.end());
    std::cout << "Мин давление: " << *minmax.first << " Макс давление: " << *minmax.second << std::endl;

    std::cout << "Давление выше 8 бар: ";
    std::for_each(pressures.begin(), pressures.end(), [](double p) {
        if (p > 8) {
            std::cout << p << " ";
        }
    });
    std::cout << std::endl;
}