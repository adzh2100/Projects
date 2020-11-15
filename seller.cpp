#include "Seller.h"

Seller::Seller(const std::string& username, const std::string& password, const std::string& adress, const std::string& phoneNumber)
	: Account(username,password,adress,phoneNumber)
{
}

void Seller::add(Product * product)
{
	products.push_back(product);
}

void Seller::remove(const unsigned& id)
{
	for (unsigned i = 0; i < products.size(); i++)
	{

		if (products[i]->getId() == id)	
		{
			for (unsigned j = i; j < products.size() - 1; j++)
			{
				products[j] = products[j + 1];
			}
			products.pop_back();
		}
	}
}

void Seller::printInfo() const
{
	
	Account::printInfo();
	std::cout << "Account type: Seller" << std::endl;
	std::cout << std::endl << "--Products for sale--"  ;
	for (unsigned i = 0; i < this->products.size(); i++)
	{
		this->products[i]->print();
		std::cout<<std::endl;
	}
}