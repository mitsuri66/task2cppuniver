#include "ArrayFilling.h"
#include "InputValidation.h"
#include "MenuItems.h"
#include <iostream>
#include <fstream>
#include <filesystem>

std::vector<Order> consoleFilling(const int numOfOrders) {
	std::string _title{};
	std::string _author{};
	std::string _recipient{};
	std::string _date{};
	int _numberOfCopies{};
	std::string _department{};
	std::string _deadline{};
	std::vector<Order> orders(numOfOrders);
	for (int i = 0; i < numOfOrders; i++) {
		std::cout << "���������� ���������� � ��������� ����������� �" << i + 1 << std::endl;
		std::cout << "������� ��������: ";
		std::getline(std::cin, _title);
		orders[i].setTitle(_title);
		std::cout << "������� ��� ������: ";
		std::getline(std::cin, _author);
		orders[i].setAuthor(_author);
		std::cout << "������� ����������: ";
		std::getline(std::cin, _recipient);
		orders[i].setRecipient(_recipient);
		std::cout << "������� ����(� ������� \"��/��/����\"): ";
		std::getline(std::cin, _date);
		while (!isValidDate(_date)) {
			std::cout << "��������� ���� ���� �����������. ��������� ����(� ������� \"��/��/����\"): ";
			std::getline(std::cin, _date);
		}
		orders[i].setDate(_date);
		std::cout << "������� ���������� �����: ";
		_numberOfCopies = getInt();
		while (_numberOfCopies <= 0) {
			std::cout << "����������� ����� �� ����� ���� �������������, ���������� �����: ";
			_numberOfCopies = getInt();
		}
		orders[i].setCopies(_numberOfCopies);
		std::cout << "������� ���������, � ������� ������������ ������: ";
		std::getline(std::cin, _department);
		orders[i].setDepartment(_department);
		std::cout << "������� ���� ��������(� ������� \"��/��/����\"): ";
		std::getline(std::cin, _deadline);
		while (!isValidDate(_deadline)) {
			std::cout << "��������� ���� ���� �����������. ��������� ����(� ������� \"��/��/����\"): ";
			std::getline(std::cin, _deadline);
		}
		orders[i].setDeadline(_deadline);
		std::cout << std::endl;
	}
	return orders;
}

bool checkFilepath(const std::string filepath) {
	std::ifstream myFile{};
	myFile.open(filepath);

	if (!std::ifstream(filepath)) {
		std::cout << "���� �� ����������. ��������� ����." << std::endl;
		myFile.close();
		return false;
	}

	std::error_code ec;
	if (!std::filesystem::is_regular_file(filepath, ec)) {
		std::cout << "����� �������� ������������ ��������. ��������� ����." << std::endl;
		myFile.close();
		return false;
	}

	if (!myFile) {
		std::cout << "�������� ���������. ��������� ����." << std::endl;
		myFile.close();
		return false;
	}
	return true;
}

int getSizeFromFile(const std::string filepath) {
	std::string data{};
	int tempLines{};
	int size{};
	std::ifstream myFile{};
	myFile.open(filepath);

	if (!checkFilepath(filepath)) {
		return 0;
	}

	while (std::getline(myFile, data)) {
		if (!data.empty()) {
			tempLines++;
		}
	}
	if (tempLines == 0) {
		std::cout << "���� ����.";
		return 0;
	}
	if (tempLines % countOfParametrs != 0) {
		std::cout << "� ����� ������������ ������.";
		myFile.close();
		return 0;
	}
	else {
		size = tempLines / countOfParametrs;
		myFile.close();
		return  size;
	}
}

std::vector<Order> fileInput(const std::string filepath) {
	std::string data{};
	int i{};
	int size{};
	std::ifstream myFile{};
	myFile.open(filepath);

	size = getSizeFromFile(filepath);
	if (size) {
		std::vector<Order> array(size);
		std::string _title{};
		std::string _author{};
		std::string _recipient{};
		std::string _date{};
		int _numberOfCopies{};
		std::string _department{};
		std::string _deadline{};
		for (i = 0; i < size; i++) {
			myFile >> _title;
			myFile >> _author;
			myFile >> _recipient;
			myFile >> _date;
			if (!isValidDate(_date)) {
				std::cout << "���� �����������. Ÿ �������� ����� �������� �� 09/07/2004\n" << std::endl;
				_date = "09/07/2004";
			}
			myFile >> _numberOfCopies;
			if (_numberOfCopies < 0) {
				std::cout << "������������� ��� ������� ����� �����. ��� ����� �������� �� 1\n";
				_numberOfCopies = 1;
			}
			myFile >> _department;
			myFile >> _deadline;
			if (!isValidDate(_deadline)) {
				std::cout << "���� �����������. Ÿ �������� ����� �������� �� 09/07/2004\n" << std::endl;
				_deadline = "09/07/2004";
			}
			array[i].setTitle(_title);
			array[i].setAuthor(_author);
			array[i].setRecipient(_recipient);
			array[i].setDate(_date);
			array[i].setCopies(_numberOfCopies);
			array[i].setDepartment(_department);
			array[i].setDeadline(_deadline);
		}
		myFile.close();
		return array;
	}
	else {
		return std::vector<Order>();
	}
}

void fileSave(std::vector<Order> orders) {
	std::string filepath{};
	bool isDataSaved = false;
	while (!isDataSaved) {
		std::cout << "������� ���� � �����, � ������� ������ ��������� ���������: ";
		std::getline(std::cin, filepath);

		if (std::ifstream(filepath)) {
			std::cout << "���� ��� ����������." << std::endl;
			std::cout << "0 - ������������ ������� ����.\n" << "1 - ������ ����� ����." << std::endl;
			int anotherFile = getInt();
			if (anotherFile) {
				continue;
			}
		}

		std::ofstream myFile(filepath, std::ofstream::app);

		std::error_code ec{};

		if (!std::filesystem::is_regular_file(filepath, ec)) {
			std::cout << "����� �������� ������������ ��������. ��������� ����." << std::endl;
			myFile.close();
			continue;
		}

		if (!myFile) {
			std::cout << "������ ���������. ��������� ����." << std::endl;
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(filepath, std::ofstream::trunc);

		for (int i = 0; i < orders.size(); i++) {
			myFile << orders[i].getTitle() << "\n" << orders[i].getAuthor() << "\n" << orders[i].getRecipient() << "\n"
				<< orders[i].getDate() << "\n" << orders[i].getCopies() << "\n" << orders[i].getDepartment() << "\n"
				<< orders[i].getDeadline() << std::endl;
		}
		myFile.close();
		std::cout << "������ ���������." << std::endl;
		isDataSaved = true;
	}

}
