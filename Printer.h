#ifndef PRINTER_H
#define PRINTER_H
#include "Product.h"

class Printer: public Product
{
private:
	std::string printingFormat;
	unsigned printingSpeed;

public:

	Printer();
	Printer(const std::string& name, double prize, const std::string& printingFormat, unsigned printingSpeed, const unsigned quantity);
	Printer(const Printer& other)=default;
	Printer& operator=(const Printer&)=default;
	virtual ~Printer()=default;

	const std::string getPrintFormat() const;
	const unsigned getPrintingSpeed() const;

	virtual void print() const override;


};
#endif