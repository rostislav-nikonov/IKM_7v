#include "Header.h"
#include <algorithm> // Для функции reverse

using namespace std;

// Функция для сложения двух больших чисел, представленных в виде строк
string summ(string num1, string num2) {
    string result = "";
    int peren = 0; // Перенос
    int i = num1.length() - 1; // Индекс для num1
    int j = num2.length() - 1; // Индекс для num2

    // Проходим с конца строк до начала
    while (i >= 0 || j >= 0 || peren) {

        int digit1; // Получаем цифру из num1 или 0
        if (i >= 0) {
            digit1 = num1[i] - '0';
        }
        else {
            digit1 = 0;
        }

        int digit2; // Получаем цифру из num2 или 0
        if (j >= 0) {
            digit2 = num2[j] - '0';
        }
        else {
            digit2 = 0;
        }

        int total = digit1 + digit2 + peren; // Суммируем цифры и перенос
        peren = total / 10; // Вычисляем новый перенос
        int digit = total % 10; // Получаем текущую цифру результата
        result += to_string(digit); // Добавляем цифру к результату
        i--;
        j--;
    }

    // Разворачиваем результат, так как мы складывали с конца
    reverse(result.begin(), result.end());
    return result;
}

// Функция для умножения большого числа (строкой) на целое число
string umnoj(string num, int x) {
    string result = "";
    int carry = 0; // Перенос

    // Проходим с конца строки
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = num[i] - '0'; // Получаем цифру
        long long temp = digit * x + carry; // Умножаем и добавляем перенос
        carry = temp / 10; // Обновляем перенос
        int current_digit = temp % 10; // Получаем текущую цифру результата
        result += to_string(current_digit); // Добавляем цифру к результату
    }

    // Обрабатываем оставшийся перенос
    while (carry > 0) {
        result += to_string(carry % 10);
        carry /= 10;
    }

    // Разворачиваем результат, так как мы складывали с конца
    reverse(result.begin(), result.end());
    return result;
}
