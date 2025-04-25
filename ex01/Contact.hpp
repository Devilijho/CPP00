#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
	public:
		Contact(void);
		~Contact();
		// Contact(const Contact &cpy); // Contact a; Contact b(a);
		// Contact &operator=(const Contact &param); // a = b;
		void	setContactInfo(void);
		void	displayContact(void);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
};
#endif
