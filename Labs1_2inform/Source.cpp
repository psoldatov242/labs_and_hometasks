#include <iostream>

/*int main()     Вариант 3, задача 1
{
    setlocale (LC_ALL, "rus");
    float a;
    std::cout << "Enter today's temperature:";
    std::cin >> a;
    if (a < 0.0)
        std::cout << "We recommend you to wear winter clothes";
    if ((0.0 <= a) and (a < 11.0))
        std::cout << "We recommend you to wear warm clothes";
    if ((11.0 <= a) and (a < 20.0))
        std::cout << "We recommend you light clothing";
    if (a > 20.0)
        std::cout << "We recommend you to wear summer clothes";
    return 0;
}
*/


/*int main()          Вариант 3, задача 2
{
    int a, b;
    b = 0;
    std::cout << "Type amount bus stops ";
    std::cin >> a;
    for (int i = 0; i < a; i++)
        b += 5;
    std::cout << b;
}
*/


#include <iostream> /*Лабораторная работа №1 - ОАиП, вариант 2*/
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int numbers[10]; /*Объявляем массив из 10 элементов*/
    for (int i = 0; i < 10; i++) {
        cout << "Введите число " << i+1 << " : ";
        cin >> numbers[i]; /*Здесь мы приняли 10 чисел от пользователя*/
    }
    cout << "Вы ввели: ";
    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << " "; /*На этом моменте мы выводим на экран 10 чисел, которые ввел пользователь*/
    }
    int summa = 0;
    for (int i = 0; i < 10; i++) {
        summa += numbers[i]; /*Ввели переменную для подсчета суммы, обнулили ее и добавили 10 элементов массива*/
    }
    cout << "Сумма чисел: " << summa << endl; /*Вывели сумму элементов на экран*/

    int maxnum = numbers[0];
    
    for (int i = 1; i < 10; i++) {
        if (numbers[i] > maxnum) {
            maxnum = numbers[i]; /*Ввели переменную для максимального числа, назначили им первый элемент. Сравниваем каждое число последовательно и переназначаем, если надо*/
        }
    }

    cout << "Максимальное число: " << maxnum << endl; /*Приступаем к сортировке, все до этого окончено*/

    for (int i = 0; i < 10; i++) { /*Шаблонная сортировка пузырьком по убыванию*/
        for (int j = 0; j < 9 - i; j++) {
            if (numbers[j] < numbers[j + 1]) { /*Если меньше число, то*/
                int smena = numbers[j]; /*Вводим временную переменную для перемещения*/
                numbers[j] = numbers[j + 1]; /*Переназначаем*/
                numbers[j + 1] = smena;
            }
        }
    }

    cout << "Отсортированные числа: "; /*Вывод отсортированных чисел на экран*/
    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl; /*Снос линии, конец проги*/
}
