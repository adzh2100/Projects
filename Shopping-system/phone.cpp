#include "Phone.h"

Phone::Phone()
	: Product()
	, displaySize(0)
	, memory (0)
{
}
Phone::Phone(std::string name, double prize, double displaySize, double memory, const unsigned quantity)
	: Product(name,prize,Category::ELECTRONICS,quantity)
	, displaySize(displaySize)
	, memory(memory)
{
}

const double Phone::getDisplaySize() const
{
	return this->displaySize;
}
const double Phone::getMemory() const
{
	return this->memory;
}

void Phone::print() const
{
	std::cout << std::endl <<std::endl<< "Product - Phone: " << this->getName();
	std::cout << std::endl << "Prize: " << this->getPrize() << "$";
	std::cout << std::endl << "Category: ELECTRONICS";
	std::cout << std::endl << "Display size: " << this->displaySize << " inches";
	std::cout << std::endl << "Memory: " << this->memory << " GB";
	std::cout << std::endl << "Product number: " << this->getId();
	std::cout << std::endl << "Available quantity: " << this->getQuantity() << std::endl;
}
