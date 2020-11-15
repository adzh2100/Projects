#include "Account.h"
#include <iostream>

Account::Account(const std::string& username, const std::string& password, const std::string& adress, const std::string& phoneNumber)
	: username(username)
	, password(password)
	, adress(adress)
	, phoneNumber(phoneNumber)
{
}

void Account::printInfo() const
{
	std::cout << std::endl << std::endl << "--Personal account--" << std::endl;
	std::cout << "Username: " << this->username<<std::endl;
	std::cout << "Adress: " << this->adress << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
}
