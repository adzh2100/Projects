#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account
{
private:
	std::string username;
	std::string password;
	std::string adress;
	std::string phoneNumber; 				
public:
	Account()=default;
	Account(const std::string&,const std::string&,const std::string&, const std::string&);
	virtual ~Account()=default;

	virtual void printInfo() const = 0;

	friend class DataBase;
};


#endif
