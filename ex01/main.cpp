#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "main.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << "Hi im ur phonebook manager, please choice a command:" << std::endl;
	while (1)
	{
		std::cout << "ADD , SEARCH , EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phonebook.setContact();
		}
		else if (input == "SEARCH")
		{
			phonebook.displayContacts();
		}
		else if (input == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break ;
		}
		else if (std::cin.eof())
		{
			std::cout << "Quiting cleanly..." << std::endl;
			break ;
		}
	}
	return (EXIT_SUCCESS);
}
