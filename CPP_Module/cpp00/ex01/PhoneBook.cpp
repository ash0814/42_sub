# include "PhoneBook.hpp"

int Contacts::addInfo(void)
{
	std::cout << "first name : ";
	if (!std::getline(std::cin, firstName))
		return (1);
	std::cout << "last name : ";
	if (!std::getline(std::cin,lastName))
		return (1);
	std::cout << "nick name : ";
	if (!std::getline(std::cin, nickName))
		return (1);
	std::cout << "phone number : ";
	if (!std::getline(std::cin, phoneNumber))
		return (1);
	std::cout << "darkest secret : ";
	if (!std::getline(std::cin, darkestSecret))
		return (1);
	return (0);
}

std::string Contacts::checkStr(std::string str)
{
	std::string ret;

	if (str.length() <= 10) {
		ret = str;
	} else {
		str[9] = '.';
		for (int i = 10; i < (int)str.length(); i++)
			str[i] = '\0';
		ret = str;
	}
	return ret;
}

void Contacts::printStr(void)
{
	std::cout << std::setw(10) << checkStr(firstName) << "|";
	std::cout << std::setw(10) << checkStr(lastName) << "|";
	std::cout << std::setw(10) << checkStr(nickName) << std::endl;
}

void PhoneBook::addContacts(Contacts ct, int i)
{
	contacts[i] = ct;
	idx++;
}

void PhoneBook::printContacts(void)
{
	int len;

	if (idx >= 8)
		len = 8;
	else
		len = idx;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout<< std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "nick Name" << std::endl;
	for (int i = 0; i < len; i++) {
		std::cout << std::setw(10) << i << "|";
		contacts[i].printStr();
	}
}

int PhoneBook::getIdx(void)
{
	return idx;
}

void PhoneBook::plusIdx(void)
{
	idx++;
}

Contacts::Contacts(/* args */)
{
}

Contacts::~Contacts()
{
}

PhoneBook::PhoneBook(/* args */)
{
	idx = 0;
}

PhoneBook::~PhoneBook()
{
}
