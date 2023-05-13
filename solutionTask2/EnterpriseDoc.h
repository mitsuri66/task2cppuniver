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
	void setTitle(const std::string _title);
	std::string getTitle();

	void setAuthor(const std::string _author);
	std::string getAuthor();

	void setRecipient(const std::string _recipient);
	std::string getRecipient();

	void setDate(const std::string _date);
	std::string getDate();

	void setCopies(const int _copies);
	int getCopies();
};

class Order : public EnterpriseDoc {
private:
	std::string department;
	std::string deadline;
public:
	void setDepartment(const std::string _department);
	std::string getDepartment();

	void setDeadline(const std::string _deadline);
	std::string getDeadline();

	void showAll();
};