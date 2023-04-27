#include "ModuleTests.h"
#include "ArrayFilling.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

bool firstTest() {
	std::string filepath = "testFile.txt";
	std::cout << "Тесты проводятся с данными из файла '" << filepath
		<< "' на проверку корректности подсчета кол-ва строк" << std::endl;
	int size = getSizeFromFile(filepath);
	if (size == 5) {
		return true;
	}
	else {
		std::cout << "Во время теста произошла ошибка." << std::endl;
		std::cout << "Ожидаемый результат: " << 5 << std::endl;
		std::cout << "Полученный результат: " << size << std::endl;
		return false;
	}
}

bool secondTest() {
	bool result = true;
	int i{};
	std::string filepath = "testFile2.txt";
	std::cout << "Тесты проводятся с данными из файла '" << filepath
		<< "' на проверку считывания данных из файла" << std::endl;
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
				std::cout << "Во время теста произошла ошибка\n" << std::endl;
				result = false;
			}
			else {
				result = true;
			}
		}
	}
	else {
		std::cout << "Во время теста произошла ошибка\n" << std::endl;
		result = false;
	}
	if (!result) {
		std::cout << "Во время выполнения теста произошла ошибка." << std::endl;
		std::cout << "Ожидаемый результат:" << std::endl;
		std::cout << "Название документа: " << "WashDishes"
			<< "\nАвтор документа: " << "Mom"
			<< "\nПолучатель документа: " << "Me"
			<< "\nДата создания: " << "22/04/2023"
			<< "\nКол-во копий: " << 4
			<< "\nОтделение, получившее документ: " << "MyRoom"
			<< "\nДата дедлайна: " << "23/04/2023" << "\n" << std::endl;
		std::cout << "Полученный результат: " << std::endl;
		for (i = 0; i < testVector.size(); i++) {
			testVector[i].showAll();
		}
	}
	return result;
}

void thirdTest() {
	std::cout << "Проводится тест на проверку функции getInt()" << std::endl;
	{
		std::istringstream input("10");

	}
}

void mainTest() {
	std::cout << std::endl;
	bool firstCheck = firstTest();
	std::cout << std::endl;
	if (firstCheck) {
		std::cout << "Первый модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Первый модульный тест не пройден." << std::endl;
	}
	std::cout << std::endl;
	bool secondCheck = secondTest();
	std::cout << std::endl;
	if (secondCheck) {
		std::cout << "Второй модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Второй модульный тест не пройден." << std::endl;
	}
	std::cout << std::endl;
	/*bool thirdCheck = thirdListTest();
	std::cout << std::endl;
	if (thirdCheck) {
		std::cout << "Третий модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Третий модульный тест не пройден." << std::endl;
	}
	std::cout << std::endl;
	bool fourthCheck = fourthTest();
	std::cout << std::endl;
	if (fourthCheck) {
		std::cout << "Четвертый модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Четвертый модульный тест не пройден." << std::endl;
	}
	std::cout << std::endl;
	bool fifthCheck = fifthTest();
	std::cout << std::endl;
	if (fifthCheck) {
		std::cout << "Пятый модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Пятый модульный тест не пройден." << std::endl;
	}*/
}