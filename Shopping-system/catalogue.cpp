#include "Catalogue.h"
#include <iostream>

void Catalogue::addProduct(Product* product)
{
	products.push_back(product);

	std::cout << "Product "<<product->getName()<< " added to catalogue successfully! " << std::endl;		//for testing
}

void Catalogue::removeProduct(const unsigned& id)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i]->getId() == id)		  //different products can't have the same id number
		{
			for (size_t j = i; j < products.size() - 1; j++)
			{
				products[j] = products[j + 1];
			}
			products.pop_back();
		}
	}

	std::cout << "Product removed from catalogue successfully!" << std::endl; //for testing
}

void Catalogue::FilterByCategory(const Category& category)
{
	std::cout << std::endl << "--Category filter applied-- "<<std::endl;
	for(size_t i=0;i<products.size();i++)
	{
		if (products[i]->getCategory() == category)
		{
			products[i]->print();
		}
	}
}
void Catalogue::SortByPrize_DO()
{
	
	for (size_t i = 0; i < products.size(); i++)
	{
		for (size_t j = 0; j<products.size() ; j++)
		{
			if (products[i]->getPrize() > products[j]->getPrize())
			{
				std::swap(products[i], products[j]);
			}
		}
	}
}
void Catalogue::SortByPrize_IO()
{
	for (size_t i = 0; i < products.size(); i++)
	{
		for (size_t j = 0; j < products.size(); j++)
		{
			if (products[i]->getPrize() < products[j]->getPrize())
			{
				std::swap(products[i], products[j]);
			}
		}
	}
}

void Catalogue::PrintCatalogue()
{
	std::cout << std::endl << std::endl << "--Catalogue--" << std::endl;

	for (size_t i = 0; i < this->products.size(); i++)
	{
		if (products[i]->getQuantity() == 0)
		{
			this->removeProduct(products[i]->getId());
		}
		//every time before we print the catalogue we remove the items which are not available
		this->products[i]->print();
	}
}
