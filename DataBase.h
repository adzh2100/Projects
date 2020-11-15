#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "Product.h"
#include "Account.h"

class DataBase
{
private:
	std::vector <Account*> accounts;
	std::vector <Product*> products;

	void addAccount(Account*);		//it is private because you can only add account by making a registation

public:

	DataBase() = default;
	DataBase(const DataBase&)=default;
	DataBase& operator=(const DataBase&)=default;
	~DataBase()=default;

	void addProduct(Product*);			
	void removeProduct(const unsigned& id);
	
	void Register(Account*); //makes a registration by account to avoid memory leaks
	void LogIn(std::string, std::string);		
	void LogOut(Account*);
	void removeAccount(std::string, std::string);
};


#endif
