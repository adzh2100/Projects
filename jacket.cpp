#include "Jacket.h"

Jacket::Jacket()
	: Product()
	, size(' ')
{

}
Jacket::Jacket(const std::string& name, double prize, const char size, const unsigned quantity)
	: Product(name,prize, Category::FASHION,quantity)
	, size(size)
{
}

char Jacket::getSize() const
{
	return this->size;
}

void Jacket::print() const
{
	std::cout << std::endl << "Product - Jacket: " << this->getName();
	std::cout << std::endl << "Prize: " << this->getPrize() << "$";
	std::cout << std::endl << "Category: FASHION";
	std::cout << std::endl << "Size: " << this->size;
	std::cout << std::endl << "Product number: " << this->getId();
	std::cout << std::endl << "Available quantity: " << this->getQuantity() << std::endl;
}