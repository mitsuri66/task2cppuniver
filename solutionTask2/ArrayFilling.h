#pragma once

#include "EnterpriseDoc.h"
#include <vector>

std::vector<Order> consoleFilling(const int); //������� ���������� ������� � �������
int getSizeFromFile(const std::string); //������� ���������� ���������� ��������� ������� � �����
std::vector<Order> fileInput(const std::string); //������� ���������� ������� �� �����
void fileSave(std::vector<Order>, const int); //������� ���������� ����������� � ����