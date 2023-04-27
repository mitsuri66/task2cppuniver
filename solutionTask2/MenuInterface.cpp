#include "MenuInterface.h"
#include <iostream>
#include <string>
#include <vector>

void showGreetings() {
	std::cout << "Здравствуйте!" << std::endl;
	std::cout << "Контрольная работа №2. Вариант №6" << std::endl;
	std::cout << "Работу выполнил: Губкин Максим\n" << "Группа №424\n" << std::endl;
}

void showTaskText() {
	std::cout << "В контрольной работе задается базовый и производный класс. Необходимо\n"
		<< "разработать поля и методы, наследуемые из базового класса, а также собственные\n"
		<< "компоненты производных классов. Базовый класс может быть абстрактным.\n"
		<< "Реализовать возможность получения списка объектов в контейнере.\n\n"
		<< "Базовый класс – документ предприятия.\n"
		<< "Производный класс – приказ" << std::endl;
}

void showMainMenu() {
	std::cout << "Выберите пункт меню:" << std::endl;
	std::cout << "1 - Ввести исходные данные с клавиатуры" << std::endl;
	std::cout << "2 - Загрузить исходные данные из файла" << std::endl;
	std::cout << "3 - Запустить модульные тесты" << std::endl;
	std::cout << "4 - Закончить работу" << std::endl;
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
			std::cout << "Сколько документов вы хотите записать? ";
			numOfOrders = getInt();
			while (numOfOrders <= 0) {
				std::cout << "Кол-во не может быть отрицательным или равным нулю. Повторите ввод: ";
				numOfOrders = getInt();
			}
			orders = consoleFilling(numOfOrders);
			std::cout << "Хотите сохранить данные в файл?\n" << "0 - Нет\n1 - Да" << std::endl;
			save = getBool();
			if (save) {
				fileSave(orders, numOfOrders);
			}
			break;
		case fstart:
			std::cout << "Ввести данные из(укажите путь к файлу): ";
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
	std::cout << "До свидания!" << std::endl;
}