#pragma once

#include "EnterpriseDoc.h"
#include <vector>

std::vector<Order> consoleFilling(const int numOfOrders); //������� ���������� ������� � �������
bool checkFilepath(const std::string filepath); //������� �������� ������������ �����
int getSizeFromFile(const std::string filepath); //������� ���������� ���������� ��������� ������� � �����
std::vector<Order> fileInput(const std::string filepath); //������� ���������� ������� �� �����
void fileSave(std::vector<Order> orders); //������� ���������� ����������� � ����