#include "EnterpriseDoc.h"

void EnterpriseDoc::setTitle(const std::string _title) {
	title = _title;
}

std::string EnterpriseDoc::getTitle() {
	return title;
}

void EnterpriseDoc::setAuthor(const std::string _author) {
	author = _author;;
}

std::string EnterpriseDoc::getAuthor() {
	return author;
}

void EnterpriseDoc::setRecipient(const std::string _recipient) {
	recipient = _recipient;
}

std::string EnterpriseDoc::getRecipient() {
	return recipient;
}

void EnterpriseDoc::setDate(const std::string _date) {
	date = _date;
}

std::string EnterpriseDoc::getDate() {
	return date;
}

void EnterpriseDoc::setCopies(const int _copies) {
	numberOfCopies = _copies;
}

int EnterpriseDoc::getCopies() {
	return numberOfCopies;
}

void Order::setDepartment(const std::string _department) {
	department = _department;
}

std::string Order::getDepartment() {
	return department;
}

void Order::setDeadline(const std::string _deadline) {
	deadline = _deadline;
}

std::string Order::getDeadline() {
	return deadline;
}

void Order::showAll() {
	std::cout << "�������� ���������: " << title
		<< "\n����� ���������: " << author
		<< "\n���������� ���������: " << recipient
		<< "\n���� ��������: " << date
		<< "\n���-�� �����: " << numberOfCopies
		<< "\n���������, ���������� ��������: " << department
		<< "\n���� ��������: " << deadline << "\n" << std::endl;
}