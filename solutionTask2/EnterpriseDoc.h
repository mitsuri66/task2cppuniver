#pragma once

#include <iostream>

class EnterpriseDoc {
protected:
	std::string title;
	std::string author;
	std::string recipient;
	std::string date;
	int numberOfCopies{};
public:
	void setTitle(const std::string);
	std::string getTitle();

	void setAuthor(const std::string);
	std::string getAuthor();

	void setRecipient(const std::string);
	std::string getRecipient();

	void setDate(const std::string);
	std::string getDate();

	void setCopies(const int);
	int getCopies();
};

class Order : public EnterpriseDoc {
private:
	std::string department;
	std::string deadline;
public:
	void setDepartment(const std::string);
	std::string getDepartment();

	void setDeadline(const std::string);
	std::string getDeadline();

	void showAll();
};