// Hometask vector - PETR SOLDATOV IU1-12B - Task 11

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Создаем вектор из 50 значений амплитуд вибрации
    std::vector<double> vibrations = {
        0.05, 0.8, 0.12, 1.2, 0.03, 0.9, 0.6, 0.08, 1.5, 0.2,
        0.15, 0.7, 0.25, 1.1, 0.04, 0.85, 0.55, 0.09, 1.3, 0.18,
        0.07, 0.75, 0.22, 1.4, 0.02, 0.95, 0.65, 0.06, 1.6, 0.16,
        0.12, 0.68, 0.28, 1.35, 0.01, 0.88, 0.58, 0.11, 1.45, 0.24,
        0.09, 0.72, 0.19, 1.25, 0.05, 0.92, 0.62, 0.07, 1.55, 0.21
    };
    
    vibrations.erase(std::remove_if(vibrations.begin(), vibrations.end(), [](double v) {
        return v < 0.1;
    }), vibrations.end());
    
    std::cout << "После удаления шумов осталось: " << vibrations.size() << " значений" << std::endl;

    double sum = 0;
    std::for_each(vibrations.begin(), vibrations.end(), [&sum](double v) {
        sum += v;
    });
    double avg = sum / vibrations.size();
    
    double max_val = *std::max_element(vibrations.begin(), vibrations.end());
    
    std::cout << "Средняя амплитуда: " << avg << std::endl;
    std::cout << "Максимальная амплитуда: " << max_val << std::endl;
    
    bool all_above = std::all_of(vibrations.begin(), vibrations.end(), [](double v) {
        return v > 0.5;
    });
    std::cout << "Все выше 0.5: " << (all_above ? "Да" : "Нет") << std::endl;
    
    std::sort(vibrations.begin(), vibrations.end(), [](double a, double b) {
        return a > b;
    });
    
    std::cout << "10 наибольших амплитуд: ";
    int count = std::min(10, (int)vibrations.size());
    std::for_each(vibrations.begin(), vibrations.begin() + count, [](double v) {
        std::cout << v << " ";
    });
}