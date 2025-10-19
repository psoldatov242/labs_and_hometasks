// Hometask vector - PETR SOLDATOV IU1-12B - Task 15

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<std::vector<double>> temp(5, std::vector<double>(30));
    std::vector<std::vector<double>> pressure(5, std::vector<double>(100));
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 30; j++) {
            temp[i][j] = 20 + i * 2 + j * 0.3;
        }
        for (int j = 0; j < 100; j++) {
            pressure[i][j] = 3 + i * 1.2 + j * 0.1;
        }
    }
    
    std::vector<double> avg_temps(5);
    for (int i = 0; i < 5; i++) {
        double sum = std::accumulate(temp[i].begin(), temp[i].end(), 0.0);
        avg_temps[i] = sum / temp[i].size();
        std::cout << "Средняя температура канала " << i << ": " << avg_temps[i] << std::endl;
    }
    
    for (int i = 0; i < 5; i++) {
        auto minmax = std::minmax_element(pressure[i].begin(), pressure[i].end());
        std::cout << "Канал " << i << " давление: мин=" << *minmax.first << " макс=" << *minmax.second << std::endl;
    }
    
    for (int i = 0; i < 5; i++) {
        double total_diff = 0;
        for (size_t j = 1; j < temp[i].size(); j++) {
            total_diff += std::abs(temp[i][j] - temp[i][j-1]);
        }
        double avg_diff = total_diff / (temp[i].size() - 1);
        std::cout << "Средняя разность температур канала " << i << ": " << avg_diff << std::endl;
    }
    
    int max_var_channel = 0;
    double max_var = 0;
    for (int i = 0; i < 5; i++) {
        auto minmax = std::minmax_element(temp[i].begin(), temp[i].end());
        double var = *minmax.second - *minmax.first;
        if (var > max_var) {
            max_var = var;
            max_var_channel = i;
        }
    }
    std::cout << "Канал с наибольшей вариацией температуры: " << max_var_channel << std::endl;
    
    std::vector<std::vector<double>> norm_pressure(5);
    for (int i = 0; i < 5; i++) {
        auto minmax = std::minmax_element(pressure[i].begin(), pressure[i].end());
        double min_val = *minmax.first;
        double max_val = *minmax.second;
        
        norm_pressure[i].resize(pressure[i].size());
        if (max_val != min_val) {
            std::transform(pressure[i].begin(), pressure[i].end(), norm_pressure[i].begin(),
                [min_val, max_val](double p) { return (p - min_val) / (max_val - min_val); });
        }
    }
    
    std::cout << "Пики давления (>0.9): ";
    for (int i = 0; i < 5; i++) {
        for (double p : norm_pressure[i]) {
            if (p > 0.9) std::cout << p << " ";
        }
    }
    std::cout << std::endl;
    
    auto max_temp_it = std::max_element(avg_temps.begin(), avg_temps.end());
    int max_temp_channel = std::distance(avg_temps.begin(), max_temp_it);
    std::cout << "Канал с макс средней температурой: " << max_temp_channel << std::endl;
    
    return 0;
}