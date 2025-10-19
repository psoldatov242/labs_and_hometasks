// Hometask vector - PETR SOLDATOV IU1-12B - Task 5

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {-51, 22, -82, 21, 49, 13, 70, 42, -65, 0, 31, 11, -43, 95, 54, -13, 33, 55, 81, -22};
    
    auto minmax = std::minmax_element(vec.begin(), vec.end());
    std::cout << "Min: " << *minmax.first << " Max: " << *minmax.second << std::endl;
    
    double sum = 0;
    std::for_each(vec.begin(), vec.end(), [&sum](int n) {
        sum += n;
    });
    double avg = sum / vec.size();
    std::cout << "Среднее: " << avg << std::endl;
    
    std::sort(vec.begin(), vec.end());
    double median = vec.size() % 2 == 0 ? 
        (vec[vec.size()/2 - 1] + vec[vec.size()/2]) / 2.0 : 
        vec[vec.size()/2];
    std::cout << "Медиана: " << median << std::endl;
}