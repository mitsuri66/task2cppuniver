#include "InputValidation.h"
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
			if (testVector[i].getTitle() != "title"
				|| testVector[i].getAuthor() != "author"
				|| testVector[i].getRecipient() != "recipient"
				|| testVector[i].getDate() != "22/04/2023"
				|| testVector[i].getCopies() != 4
				|| testVector[i].getDepartment() != "department"
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
		std::cout << "�������� ���������: " << "title"
			<< "\n����� ���������: " << "author"
			<< "\n���������� ���������: " << "recipient"
			<< "\n���� ��������: " << "22/04/2023"
			<< "\n���-�� �����: " << 4
			<< "\n���������, ���������� ��������: " << "department"
			<< "\n���� ��������: " << "23/04/2023" << "\n" << std::endl;
		std::cout << "���������� ���������: " << std::endl;
		for (i = 0; i < testVector.size(); i++) {
			testVector[i].showAll();
		}
	}
	return result;
}

bool thirdTest() {
	std::cout << "���������� ���� �� �������� ������� getInt()" << std::endl;
	{
		std::istringstream input("10");
		std::streambuf* cinbuf = std::cin.rdbuf(input.rdbuf());

		bool result = (getInt() == 10);
		if (result) {
			std::cout << "���� 1: �������" << std::endl;
		}
		else {
			std::cout << "���� 1: ��������" << std::endl;
			return false;
		}

		std::cin.rdbuf(cinbuf);
	}

	{
		std::istringstream input("zxc\n10\n");
		std::streambuf* cinbuf = std::cin.rdbuf(input.rdbuf());

		bool result = (getInt() == 10);
		if (result) {
			std::cout << "���� 2: �������" << std::endl;
		}
		else {
			std::cout << "���� 2: ��������" << std::endl;
			return false;
		}

		std::cin.rdbuf(cinbuf);
	}
	return true;
}

bool fourthTest() {
	std::cout << "���������� ���� �� �������� ������� isValidDate()" << std::endl;
	std::cout << "����� ���������� ��������� ������ � ���������� �������� ��������:\n"
		<< "1: \"10/10/2022\"\n2: \"32/13/2123\"\n3: \"10.10.2022\"\n4: \"10:10:2023\"\n5: \"10/10/10/2023\"" << std::endl;
	if (isValidDate("10/10/2022")) {
		std::cout << "���� 1: �������" << std::endl;
	}
	else {
		std::cout << "���� 1: ��������" << std::endl;
		return false;
	}
	if (!isValidDate("32/13/2123")) {
		std::cout << "���� 2: �������" << std::endl;
	}
	else {
		std::cout << "���� 2: ��������" << std::endl;
		return false;
	}
	if (!isValidDate("10.10.2022")) {
		std::cout << "���� 3: �������" << std::endl;
	}
	else {
		std::cout << "���� 3: ��������" << std::endl;
		return false;
	}
	if (!isValidDate("10:10:2023")) {
		std::cout << "���� 4: �������" << std::endl;
	}
	else {
		std::cout << "���� 4: ��������" << std::endl;
		return false;
	}
	if (!isValidDate("10/10/10/2023")) {
		std::cout << "���� 5: �������" << std::endl;
	}
	else {
		std::cout << "���� 5: ��������" << std::endl;
		return false;
	}
	return true;
}

bool fifthTest() {
	return true;
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
	bool thirdCheck = thirdTest();
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
	/*bool fifthCheck = fifthTest();
	std::cout << std::endl;
	if (fifthCheck) {
		std::cout << "����� ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "����� ��������� ���� �� �������." << std::endl;
	}*/
}