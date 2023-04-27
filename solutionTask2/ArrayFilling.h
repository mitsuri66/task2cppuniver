#pragma once

#include "EnterpriseDoc.h"
#include <vector>

std::vector<Order> consoleFilling(const int); //функция заполнения массива с консоли
int getSizeFromFile(const std::string); //функция вычисления количества элементов массива в файле
std::vector<Order> fileInput(const std::string); //функция заполнения массива из файла
void fileSave(std::vector<Order>, const int); //функция сохранения результатов в файл