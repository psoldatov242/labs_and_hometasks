// Hometask vector - PETR SOLDATOV IU1-12B - Task 14

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<double> hourly_usage;
    double hour_value;

    for (int hour = 0; hour < 24; hour++) {
        std::cin >> hour_value;
        hourly_usage.push_back(hour_value);
    }

    auto minmax_hours = std::minmax_element(hourly_usage.begin(), hourly_usage.end());
    double total_consumption = std::accumulate(hourly_usage.begin(), hourly_usage.end(), 0.0);
    double mean_consumption = total_consumption / hourly_usage.size();
    
    std::cout << "Всего потрачено энергии " << total_consumption << std::endl;
    std::cout << "Средняя затрата в чат " << mean_consumption << std::endl;

    std::cout << "Пиковые часы ";
    int hour_count = 0;
    std::for_each(hourly_usage.begin(), hourly_usage.end(), [&minmax_hours, &hour_count](double usage) {
        if (usage == *minmax_hours.second) {
            std::cout << "Hour " << hour_count << " (" << usage << "), ";
        }
        hour_count++;
    });
    std::cout << std::endl;

    std::vector<double> deviations(hourly_usage.size());
    std::transform(hourly_usage.begin(), hourly_usage.end(), deviations.begin(), 
                   [mean_consumption](double usage) { return usage - mean_consumption; });

    std::cout << "Среднее отклонение ";
    std::for_each(deviations.begin(), deviations.end(), [](double diff) {
        std::cout << diff << " ";
    });
    std::cout << std::endl;

    std::vector<double> sorted_usage = hourly_usage;
    std::sort(sorted_usage.begin(), sorted_usage.end());

    std::cout << "5 наименьших значений: ";
    std::for_each(sorted_usage.begin(), sorted_usage.begin() + 5, [](double low_usage) {
        std::cout << low_usage << " ";
    });
    std::cout << std::endl;
}