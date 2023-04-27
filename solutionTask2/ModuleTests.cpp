#include "ModuleTests.h"
#include "ArrayFilling.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

bool firstTest() {
	std::string filepath = "testFile.txt";
	std::cout << "����� ���������� � ������� �� ����� '" << filepath
		<< "' �� �������� ������������ �������� ���-�� �����" << std::endl;
	int size = getSizeFromFile(filepath);
	if (size == 5) {
		return true;
	}
	else {
		std::cout << "�� ����� ����� ��������� ������." << std::endl;
		std::cout << "��������� ���������: " << 5 << std::endl;
		std::cout << "���������� ���������: " << size << std::endl;
		return false;
	}
}

bool secondTest() {
	bool result = true;
	int i{};
	std::string filepath = "testFile2.txt";
	std::cout << "����� ���������� � ������� �� ����� '" << filepath
		<< "' �� �������� ���������� ������ �� �����" << std::endl;
	std::vector<Order> testVector = fileInput(filepath);
	if (testVector.size() == 1) {
		for (i = 0; i < testVector.size(); i++) {
			if (testVector[i].getTitle() != "WashDishes"
				|| testVector[i].getAuthor() != "Mom"
				|| testVector[i].getRecipient() != "Me"
				|| testVector[i].getDate() != "22/04/2023"
				|| testVector[i].getCopies() != 4
				|| testVector[i].getDepartment() != "MyRoom"
				|| testVector[i].getDeadline() != "23/04/2023") {
				std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
				result = false;
			}
			else {
				result = true;
			}
		}
	}
	else {
		std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
		result = false;
	}
	if (!result) {
		std::cout << "�� ����� ���������� ����� ��������� ������." << std::endl;
		std::cout << "��������� ���������:" << std::endl;
		std::cout << "�������� ���������: " << "WashDishes"
			<< "\n����� ���������: " << "Mom"
			<< "\n���������� ���������: " << "Me"
			<< "\n���� ��������: " << "22/04/2023"
			<< "\n���-�� �����: " << 4
			<< "\n���������, ���������� ��������: " << "MyRoom"
			<< "\n���� ��������: " << "23/04/2023" << "\n" << std::endl;
		std::cout << "���������� ���������: " << std::endl;
		for (i = 0; i < testVector.size(); i++) {
			testVector[i].showAll();
		}
	}
	return result;
}

void thirdTest() {
	std::cout << "���������� ���� �� �������� ������� getInt()" << std::endl;
	{
		std::istringstream input("10");

	}
}

void mainTest() {
	std::cout << std::endl;
	bool firstCheck = firstTest();
	std::cout << std::endl;
	if (firstCheck) {
		std::cout << "������ ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "������ ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool secondCheck = secondTest();
	std::cout << std::endl;
	if (secondCheck) {
		std::cout << "������ ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "������ ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	/*bool thirdCheck = thirdListTest();
	std::cout << std::endl;
	if (thirdCheck) {
		std::cout << "������ ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "������ ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool fourthCheck = fourthTest();
	std::cout << std::endl;
	if (fourthCheck) {
		std::cout << "��������� ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "��������� ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool fifthCheck = fifthTest();
	std::cout << std::endl;
	if (fifthCheck) {
		std::cout << "����� ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "����� ��������� ���� �� �������." << std::endl;
	}*/
}