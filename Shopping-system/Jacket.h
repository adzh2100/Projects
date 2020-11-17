#ifndef JACKET_H
#define JACKET_H
#include "Product.h"

class Jacket: public Product
{
private:
	char size;  //S,M,L 
public:

	Jacket();
	Jacket(const std::string& name, double prize, const char size, const unsigned quantity);
	Jacket(const Jacket&) = default;
	Jacket& operator=(const Jacket&) = default;
	~Jacket() = default;

	char getSize() const;

	virtual void print() const override;

};

#endif
