#include "Cart.h"
#include <iostream>

Cart::Cart()
	: products(std::vector<Product*>())
	, totalPrize(0)
{
}
void Cart::add(Product* product)
{
	products.push_back(product);

	this->totalPrize += product->getPrize();				//adds the product's price to the total value

	std::cout << std::endl << "Product "<<product->getName()<<" added to cart successfully! ";
}

void Cart::remove(const unsigned& id)
{
	
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i]->getId() == id)						    //different products can't have the same id number
		{
			this->totalPrize -= products[i]->getPrize();		//removes the product's price from the total value

			for (size_t j = i; j < products.size()-1; j++)
			{
				products[j] = products[j + 1];
			}
			products.pop_back();
		}
	}

	std::cout << std::endl << "Product with ID "<<id<<" removed from cart successfully! " << std::endl;
}

double Cart::getTotalPrize() const
{
	return this->totalPrize;
}

void Cart::print() const
{
	std::cout << std::endl<<std::endl << "--Cart--" << std::endl;
	for (size_t i = 0; i < products.size(); i++)
	{
		products[i]->print();
	}
	std::cout << std::endl << "Total price: " << this->totalPrize << std::endl<<std::endl;
}

void Cart::Purchase()
{
	while(this->products.size()!=0)
	{
		unsigned size =this->products.size() - 1;
		this->products[size]->setQuantity(this->products[size]->getQuantity() - 1);
		this->products.pop_back();
	}
	this->totalPrize = 0;
}