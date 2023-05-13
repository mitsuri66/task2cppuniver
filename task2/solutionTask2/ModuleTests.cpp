#include "InputValidation.h"
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
			if (testVector[i].getTitle() != "title"
				|| testVector[i].getAuthor() != "author"
				|| testVector[i].getRecipient() != "recipient"
				|| testVector[i].getDate() != "22/04/2023"
				|| testVector[i].getCopies() != 4
				|| testVector[i].getDepartment() != "department"
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
		std::cout << "Название документа: " << "title"
			<< "\nАвтор документа: " << "author"
			<< "\nПолучатель документа: " << "recipient"
			<< "\nДата создания: " << "22/04/2023"
			<< "\nКол-во копий: " << 4
			<< "\nОтделение, получившее документ: " << "department"
			<< "\nДата дедлайна: " << "23/04/2023" << "\n" << std::endl;
		std::cout << "Полученный результат: " << std::endl;
		for (i = 0; i < testVector.size(); i++) {
			testVector[i].showAll();
		}
	}
	return result;
}

bool thirdTest() {
	std::cout << "Проводится тест на проверку функции getInt()" << std::endl;
	{
		std::istringstream input("10");
		std::streambuf* cinbuf = std::cin.rdbuf(input.rdbuf());

		bool result = (getInt() == 10);
		if (result) {
			std::cout << "Тест 1: успешно" << std::endl;
		}
		else {
			std::cout << "Тест 1: провален" << std::endl;
			return false;
		}

		std::cin.rdbuf(cinbuf);
	}

	{
		std::istringstream input("zxc\n10\n");
		std::streambuf* cinbuf = std::cin.rdbuf(input.rdbuf());

		bool result = (getInt() == 10);
		if (result) {
			std::cout << "Тест 2: успешно" << std::endl;
		}
		else {
			std::cout << "Тест 2: провален" << std::endl;
			return false;
		}

		std::cin.rdbuf(cinbuf);
	}
	return true;
}

bool fourthTest() {
	std::cout << "Проводится тест на проверку функции isValidDate()" << std::endl;
	std::cout << "Будет проводится несколько тестов с различными наборами значений:\n"
		<< "1: \"10/10/2022\"\n2: \"32/13/2123\"\n3: \"10.10.2022\"\n4: \"10:10:2023\"\n5: \"10/10/10/2023\"" << std::endl;
	if (isValidDate("10/10/2022")) {
		std::cout << "Тест 1: успешно" << std::endl;
	}
	else {
		std::cout << "Тест 1: провален" << std::endl;
		return false;
	}
	if (!isValidDate("32/13/2123")) {
		std::cout << "Тест 2: успешно" << std::endl;
	}
	else {
		std::cout << "Тест 2: провален" << std::endl;
		return false;
	}
	if (!isValidDate("10.10.2022")) {
		std::cout << "Тест 3: успешно" << std::endl;
	}
	else {
		std::cout << "Тест 3: провален" << std::endl;
		return false;
	}
	if (!isValidDate("10:10:2023")) {
		std::cout << "Тест 4: успешно" << std::endl;
	}
	else {
		std::cout << "Тест 4: провален" << std::endl;
		return false;
	}
	if (!isValidDate("10/10/10/2023")) {
		std::cout << "Тест 5: успешно" << std::endl;
	}
	else {
		std::cout << "Тест 5: провален" << std::endl;
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
	bool thirdCheck = thirdTest();
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
	/*bool fifthCheck = fifthTest();
	std::cout << std::endl;
	if (fifthCheck) {
		std::cout << "Пятый модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Пятый модульный тест не пройден." << std::endl;
	}*/
}