#include "Printer.h"

Printer::Printer()
	: Product()
	, printingFormat("")
	, printingSpeed(0)
{
}
Printer::Printer(const std::string& name, double prize,const std::string& printingFormat, unsigned printingSpeed, const unsigned quantity)
	: Product(name, prize, Category::ELECTRONICS,quantity)
	, printingFormat(printingFormat)
	, printingSpeed(printingSpeed)
{
}

const std::string Printer::getPrintFormat() const
{
	return this->printingFormat;
}
const unsigned Printer::getPrintingSpeed() const
{
	return this->printingSpeed;
}

void Printer::print() const
{
	std::cout << std::endl << "Product - Printer: " << this->getName();
	std::cout << std::endl << "Prize: " << this->getPrize()<< "$";
	std::cout << std::endl << "Category: ELECTRONICS";
	std::cout << std::endl<<"Printing format: " << this->printingFormat;
	std::cout <<std::endl<<"Printing speed: " << this->printingSpeed<< " pps";
	std::cout << std::endl << "Product number: " << this->getId();
	std::cout << std::endl << "Available quantity: " << this->getQuantity() << std::endl;
}
