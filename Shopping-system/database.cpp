#include "DataBase.h"
#include "Customer.h"
#include "Seller.h"

void DataBase::addProduct(Product* product)
{

	products.push_back(product);
	std::cout << "Product "<< product->getName()<<" added to Data Base successfully! " << std::endl;  //only for testing
}

void DataBase::removeProduct(const unsigned& id)
{

	for (unsigned i = 0; i < products.size(); i++)
	{
		if (products[i]->getId() == id)		  //different products can't have the same id number
		{
			for (unsigned j = i; j < products.size() - 1; j++)
			{
				products[j] = products[j + 1];
			}
			products.pop_back();
		}
	}

	std::cout << "Product with ID "<< id <<" removed from Data Base successfully! " << std::endl;  //only for testing
}

void DataBase::addAccount(Account* account)
{
	accounts.push_back(account);
	//std::cout << "Account added to Data Base successfully! " << std::endl; 
}

void DataBase::removeAccount(std::string username, std::string password)
{
	for (unsigned i = 0; i < this->accounts.size(); i++)
	{
		if (this->accounts[i]->username==username && this->accounts[i]->password==password)
		{
			for (unsigned j = i; j < accounts.size() - 1; j++)
			{
				accounts[j] = accounts[j + 1];
			}
			accounts.pop_back();
		}
	}
	std::cout << "Account removed from Data Base successfully! " << std::endl;  //only for testing
}

void DataBase::LogIn(std::string username, std::string password)
{
	for (unsigned i = 0; i < this->accounts.size(); i++)
	{
		if (this->accounts[i]->username == username && this->accounts[i]->password == password)
		{
			std::cout << "You have logged in successfully" << std::endl;
			return;
		}
	}
	std::cout << "Incorrect username or password." << std::endl;
}

void DataBase::Register(Account* account)
{
	//i am making a registration by an already created account
	//because i dont want my database to know about the existance of specific account types

	for (unsigned i = 0; i < this->accounts.size(); i++)
	{
		if (this->accounts[i]->username == account->username)
		{
			std::cout << "This username already exists! Choose another one." << std::endl;
			return;
		}
	}
	this->addAccount(account);
	std::cout << std::endl << "You have registered successfulyy! " << std::endl;
}

void DataBase::LogOut(Account* acc)
{
	std::cout << "You have logged out successfully!" << std::endl;
}
