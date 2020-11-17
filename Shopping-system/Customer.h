#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Account.h"
#include "Product.h"
#include "Cart.h"

class Customer : public Account
{
private:
	Cart cart;
public:
	Customer()=default;
	Customer(const std::string&, const std::string&, const std::string&, const std::string&);
	virtual ~Customer() = default;

	void addToCart(Product*);
	void removeFromCart(const unsigned& id);
	void viewCart() const;
	void Purchase();

	virtual void printInfo() const override;
};

#endif 
