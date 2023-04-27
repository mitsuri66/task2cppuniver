#include "InputValidation.h"
#include <iostream>
#include <sstream>

template<typename T>
T getInput() {
    T userInput{};
    std::cin >> userInput;
    if (std::cin.fail()) {
        std::cout << "������������ ��������, ��������� �������." << std::endl;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cin >> userInput;
        }
    }
    std::cin.ignore(INT_MAX, '\n');
    return userInput;
}

int getInt() {
    return getInput<int>();
}

bool getBool() {
    int x = getInt();
    while (x != 0 && x != 1) {
        std::cout << "�� ������ ������ ������ 1 ��� 0";
        x = getInt();
    }
    return static_cast<bool>(x);
}

bool isValidDate(const std::string dateStr)
{
    std::stringstream ss(dateStr);
    int day, month, year;
    char delim;

    if (ss >> day && ss >> delim && delim == '/' && ss >> month &&
        ss >> delim && delim == '/' && ss >> year && ss.eof())
    {
        // ��������� ��������� ����, ������� � �����
        if (day < 1 || day > 31 || month < 1 || month > 12 || year <= 0 || year > 2023)
        {
            return false;
        }
        // ��������� ������������ ���� � �������
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        {
            return false;
        }
        if (month == 2)
        {
            bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (day > 29 || (day == 29 && !isLeapYear))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}