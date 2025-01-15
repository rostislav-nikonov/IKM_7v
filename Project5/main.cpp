#include <iostream>
#include <string>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;
    cout << "Введите значение n (n > 10 (при вводе дробных чисел, дробная часть отбрасывается)): ";
    cin >> n;

    // Проверка корректности ввода
    if (n < 10) {
        cout << "Ошибка: n должно быть числом превышающим 10." << endl;
        return 1;
    }

    string sum = "0";         
    string factorial = "1";   

    // Вычисление суммы ряда 1! + 2! + ... + n!
    for (int i = 1; i <= n; i++) {
        // Вычисляем i! как (i-1)! * i
        factorial = umnoj(factorial, i);
        // Складываем текущий факториал к общей сумме
        sum = summ(sum, factorial);
    }

    cout << "Сумма ряда 1! + 2! + ... + " << n << "! = " << sum << endl;

    return 0;
}
