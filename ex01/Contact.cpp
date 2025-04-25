#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact(void)
{
	this->_first_name = std::string();
	this->_last_name = std::string();
	this->_nickname = std::string();
	this->_phone_number = std::string();
	this->_darkest_secret = std::string();
}

std::string	get_input(std::string message)
{
	std::string buffer;

	while (buffer.empty())
	{
		std::cout << message << std::endl;
		std::getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cout << "Quitting cleanly" << std::endl;
			exit (1);
		}
		if (buffer.empty())
		{
			std::cout << "Cannot have a empty input" << std::endl;
		}
	}
	return (buffer);
}

void	Contact::displayContact()
{
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty() || this->_phone_number.empty() || this->_darkest_secret.empty())
	{
		std::cout << "Contact is empty" << std::endl;
		return ;
	}
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << getDarkestSecret() << std::endl;
}

void	Contact::setContactInfo()
{
	this->_first_name = get_input("Enter your first name: ");
	this->_last_name = get_input("Enter your last name: ");
	this->_nickname = get_input("Enter your nickname: ");
	this->_phone_number = get_input("Enter your phone number: ");
	this->_darkest_secret = get_input("Enter your darkest secret: ");
}

std::string	Contact::getFirstName(void) const
{
	return (this->_first_name);
}

std::string	Contact::getLastName(void) const
{
	return (this->_last_name);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phone_number);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkest_secret);
}

Contact::~Contact(){}
