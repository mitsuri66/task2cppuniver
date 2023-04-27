#include "MenuInterface.h"
#include <iostream>
#include <string>
#include <vector>

void showGreetings() {
	std::cout << "������������!" << std::endl;
	std::cout << "����������� ������ �2. ������� �6" << std::endl;
	std::cout << "������ ��������: ������ ������\n" << "������ �424\n" << std::endl;
}

void showTaskText() {
	std::cout << "� ����������� ������ �������� ������� � ����������� �����. ����������\n"
		<< "����������� ���� � ������, ����������� �� �������� ������, � ����� �����������\n"
		<< "���������� ����������� �������. ������� ����� ����� ���� �����������.\n"
		<< "����������� ����������� ��������� ������ �������� � ����������.\n\n"
		<< "������� ����� � �������� �����������.\n"
		<< "����������� ����� � ������" << std::endl;
}

void showMainMenu() {
	std::cout << "�������� ����� ����:" << std::endl;
	std::cout << "1 - ������ �������� ������ � ����������" << std::endl;
	std::cout << "2 - ��������� �������� ������ �� �����" << std::endl;
	std::cout << "3 - ��������� ��������� �����" << std::endl;
	std::cout << "4 - ��������� ������" << std::endl;
}

void showArray(std::vector<Order> array) {
	for (int i = 0; i < array.size(); i++) {
		array[i].showAll();
		std::cout << std::endl;
	}
}

void startProgram() {
	bool quit = false;
	bool save{};
	std::vector<Order> orders{};
	std::string filepath{};
	int numOfOrders{};
	int programSelection{};
	showGreetings();
	showTaskText();
	while (!quit) {
		showMainMenu();
		programSelection = getInt();
		switch (programSelection) {
		case start:
			std::cout << "������� ���������� �� ������ ��������? ";
			numOfOrders = getInt();
			while (numOfOrders <= 0) {
				std::cout << "���-�� �� ����� ���� ������������� ��� ������ ����. ��������� ����: ";
				numOfOrders = getInt();
			}
			orders = consoleFilling(numOfOrders);
			std::cout << "������ ��������� ������ � ����?\n" << "0 - ���\n1 - ��" << std::endl;
			save = getBool();
			if (save) {
				fileSave(orders, numOfOrders);
			}
			break;
		case fstart:
			std::cout << "������ ������ ��(������� ���� � �����): ";
			std::getline(std::cin, filepath);
			orders = fileInput(filepath);
			std::cout << std::endl;
			showArray(orders);
			break;
		case tests:
			mainTest();
			break;
		case end:
			quit = true;
			break;
		}
	}
	orders.clear();
	std::cout << "�� ��������!" << std::endl;
}