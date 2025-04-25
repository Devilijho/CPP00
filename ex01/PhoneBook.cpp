#include "PhoneBook.hpp"

std::string formatColumn(const std::string& text) {
	if (text.length() > 10) {
		return text.substr(0, 9) + ".";
	}
	return std::string(10 - text.length(), ' ') + text;
}

std::string to_string(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

int	checkIndex(const std::string& index)
{
	for (u_long i = 0; i < index.length(); i++)
	{
		if (!isdigit(index[i]))
		{
			return (-1);
		}
	}
	return (atoi(index.c_str()));
}

PhoneBook::PhoneBook()
{
	this->_index = 0;
}

void PhoneBook::setContact()
{
	this->_contacts[_index].setContactInfo();
	std::cout << "Contact added successfully!" << std::endl;
	this->updateIndex();
}

void PhoneBook::displayContacts()
{
	long index = 0;

	std::cout << formatColumn("index") << "|" << formatColumn("first name") << "|"
		<< formatColumn("last Name") << "|" << formatColumn("nickname") << std::endl;
	while (index < 8)
	{
		std::cout << formatColumn(to_string(index)) << "|"
			<< formatColumn(_contacts[index].getFirstName()) << "|"
			<< formatColumn(_contacts[index].getLastName()) << "|"
			<< formatColumn(_contacts[index].getNickname()) << std::endl;
		index++;
	}
	index = this->getContactIndex();
	if (index >= 0 && index < 8)
		this->_contacts[index].displayContact();
	else
		std::cout << "Invalid index" << std::endl;
}

int	PhoneBook::getContactIndex(void)
{
	std::string index;

	while (index.empty())
	{
		std::cout << "Enter index: ";
		std::getline(std::cin, index);
		if (std::cin.eof())
		{
			std::cout << "Quitting cleanly" << std::endl;
			exit (1);
		}
	}
	return (checkIndex(index));
}

void PhoneBook::updateIndex(void)
{
	_index++;
	if (_index == 8)
		_index = 0;
}

PhoneBook::~PhoneBook()
{
}
