#ifndef PHONE_H
#define PHONE_H
#include "Product.h"

class Phone:public Product
{
private:
	double displaySize;
	double memory;
public:

	Phone();
	Phone(std::string name, double prize, double displaySize,double memory, const unsigned quantity);
	Phone(const Phone&) = default;
	Phone& operator=(const Phone&) = default;
	~Phone() = default;

	const double getDisplaySize() const;
	const double getMemory() const;
	virtual void print() const override;

};
#endif