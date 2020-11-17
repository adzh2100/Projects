#include "Product.h"

unsigned Product::nextID = 0;

Product::Product()
	: name("")
	, prize(0)
	, category(Category::ELECTRONICS)
	, id(++nextID)
	, quantity(0)
{
}
Product::Product(const std::string& name, const double& prize, const Category& category,const unsigned quantity)
	: name(name)
	, prize(prize)
	, category(category)
	, quantity(quantity)
	, id(++nextID)
{
}

const std::string Product::getName() const
{
	return this->name;
}

const double Product::getPrize() const
{
	return this->prize;
}

const Category Product::getCategory() const
{
	return this->category;
}

const int Product::getId() const
{
	return this->id;
}

const unsigned Product::getQuantity() const
{
	return this->quantity;
}

void Product::setQuantity(const unsigned quantity)
{
	this->quantity = quantity;
}
