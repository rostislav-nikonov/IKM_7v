// main.cpp
#include <iostream>
#include <string>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main() {
    // ��������� ��������� ������� (�����������)
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;
    cout << "������� �������� n (n > 10 (��� ����� ������� �����, ������� ����� �������������)): ";
    cin >> n;

    // �������� ������������ �����
    if (n < 10) {
        cout << "������: n ������ ���� ������ ����������� 10." << endl;
        return 1;
    }

    string sum = "0";          // ������������� �����
    string factorial = "1";    // ������������� ���������� (1!)

    // ���������� ����� ���� 1! + 2! + ... + n!
    for (int i = 1; i <= n; i++) {
        // ��������� i! ��� (i-1)! * i
        factorial = umnoj(factorial, i);
        // ���������� ������� ��������� � ����� �����
        sum = summ(sum, factorial);
    }

    cout << "����� ���� 1! + 2! + ... + " << n << "! = " << sum << endl;

    return 0;
}
