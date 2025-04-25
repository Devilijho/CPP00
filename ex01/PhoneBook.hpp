#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <sys/types.h>
#include <cstring>
#include <sstream>

std::string formatColumn(const std::string& text);

class PhoneBook
{
	private:
		int		_index;
		Contact _contacts[8];
		void 	updateIndex(void);
		int		getContactIndex(void);
	public:
		PhoneBook();
		~PhoneBook();
		void setContact();
		void displayContacts();
};
#endif
