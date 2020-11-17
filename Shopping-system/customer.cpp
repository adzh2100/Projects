#include "Customer.h"


Customer::Customer(const std::string& username, const std::string& password, const std::string& adress, const std::string& phoneNumber)
	: Account(username,password,adress,phoneNumber)
{
}
void Customer::addToCart(Product* product)
{
	this->cart.add(product);
}

void Customer::removeFromCart(const unsigned& id)
{
	this->cart.remove(id);
}

void Customer::viewCart() const
{
	this->cart.print();
}

void Customer::Purchase()
{
	std::cout << "Purchase successful! Total value: " << this->cart.getTotalPrize() <<" $"<< std::endl;
	this->cart.Purchase();
}

void Customer::printInfo() const
{
	
	Account::printInfo();
	std::cout << "Account type: Customer" << std::endl;
}
