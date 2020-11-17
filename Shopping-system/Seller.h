#ifndef SELLER_H
#define SELLER_H
#include "Account.h"
#include "Product.h"
#include <vector>

class Seller: public Account
{
private:
	std::vector<Product*> products;
public:
	Seller() = default;
	Seller(const std::string& username, const std::string& password, const std::string& adress, const std::string& phoneNumber);
	virtual ~Seller() = default;

	void add(Product*);
	void remove(const unsigned& id);

	virtual void printInfo() const override;
};
#endif
