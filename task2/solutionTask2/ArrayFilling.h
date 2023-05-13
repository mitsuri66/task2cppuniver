#pragma once

#include "EnterpriseDoc.h"
#include <vector>

std::vector<Order> consoleFilling(const int numOfOrders); //функция заполнения массива с консоли
bool checkFilepath(const std::string filepath); //функция проверки корректности файла
int getSizeFromFile(const std::string filepath); //функция вычисления количества элементов массива в файле
std::vector<Order> fileInput(const std::string filepath); //функция заполнения массива из файла
void fileSave(std::vector<Order> orders); //функция сохранения результатов в файл