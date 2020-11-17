#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>

enum class Category
{
	ELECTRONICS,
	FASHION,
	BOOKS
};

class Product
{
private:
	std::string name;
	double prize;
	Category category;
	unsigned quantity;
	int id;		
	static unsigned nextID;	

public:
	Product();
	Product(const std::string&, const double&, const Category&, const unsigned quantity);
	Product(const Product&)=default;
	Product& operator=(const Product&)=default;
	virtual ~Product() = default;

	virtual const std::string getName() const;
	virtual const double getPrize() const;			 
	virtual const Category getCategory() const;		 
	virtual const int getId() const;
	virtual const unsigned getQuantity() const;
	virtual void setQuantity(const unsigned);
	
	virtual void print() const=0;
};

#endif
