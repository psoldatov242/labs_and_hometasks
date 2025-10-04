// Hometask Geometry - PETR SOLDATOV IU1-12B - Task 4

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    vector<double> x(4), y(4);
    
    cout << "Введите координаты вершин прямоугольника:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Вершина " << i+1 << " (x y): ";
        cin >> x[i] >> y[i];
    }
    
    // Берем первую и третью вершины как противоположные
    //Оч долгая проверка на то что вершины составляют прямоугольник - я понимаю, что моя задача этоого не учитывает, но иначе будет много формул чисто математических, долго переписывающихся в код
    double dx = x[2] - x[0];
    double dy = y[2] - y[0];
    double diagonal = sqrt(dx*dx + dy*dy);
    
    cout << "Длина диагонали прямоугольника: " << diagonal << endl;
    
    return 0;
}