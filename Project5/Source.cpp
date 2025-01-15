#include "Header.h"
#include <algorithm> // ��� ������� reverse

using namespace std;

// ������� ��� �������� ���� ������� �����, �������������� � ���� �����
string summ(string num1, string num2) {
    string result = "";
    int peren = 0; // �������
    int i = num1.length() - 1; // ������ ��� num1
    int j = num2.length() - 1; // ������ ��� num2

    // �������� � ����� ����� �� ������
    while (i >= 0 || j >= 0 || peren) {

        int digit1; // �������� ����� �� num1 ��� 0
        if (i >= 0) {
            digit1 = num1[i] - '0';
        }
        else {
            digit1 = 0;
        }

        int digit2; // �������� ����� �� num2 ��� 0
        if (j >= 0) {
            digit2 = num2[j] - '0';
        }
        else {
            digit2 = 0;
        }

        int total = digit1 + digit2 + peren; // ��������� ����� � �������
        peren = total / 10; // ��������� ����� �������
        int digit = total % 10; // �������� ������� ����� ����������
        result += to_string(digit); // ��������� ����� � ����������
        i--;
        j--;
    }

    // ������������� ���������, ��� ��� �� ���������� � �����
    reverse(result.begin(), result.end());
    return result;
}

// ������� ��� ��������� �������� ����� (�������) �� ����� �����
string umnoj(string num, int x) {
    string result = "";
    int carry = 0; // �������

    // �������� � ����� ������
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = num[i] - '0'; // �������� �����
        long long temp = digit * x + carry; // �������� � ��������� �������
        carry = temp / 10; // ��������� �������
        int current_digit = temp % 10; // �������� ������� ����� ����������
        result += to_string(current_digit); // ��������� ����� � ����������
    }

    // ������������ ���������� �������
    while (carry > 0) {
        result += to_string(carry % 10);
        carry /= 10;
    }

    // ������������� ���������, ��� ��� �� ���������� � �����
    reverse(result.begin(), result.end());
    return result;
}
