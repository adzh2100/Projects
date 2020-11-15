#ifndef CART_H
#define CART_H
#include "Product.h"
#include <vector>
class Cart
{
private:
	std::vector <Product*> products;
	double totalPrize;

	void add(Product*);	
	void remove(const unsigned& id);			//they are all private because you can have access to the cart only if you have a customer account
	void print() const;			
	void Purchase();
public:
	Cart();
	Cart(const Cart&) = default;
	Cart& operator=(const Cart&) = default;
	~Cart() = default;

	double getTotalPrize() const;
	friend class Customer;
};
#endif