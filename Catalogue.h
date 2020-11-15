#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "Product.h"
#include <vector>
class Catalogue								
{
private:
	std::vector <Product*> products;

public:
	Catalogue()=default;
	Catalogue(const Catalogue&) = default;
	Catalogue& operator=(const Catalogue&) = default;
	~Catalogue() = default;

	void addProduct(Product*);
	void removeProduct(const unsigned& id);
	void FilterByCategory(const Category&);
	void SortByPrize_DO(); //decreasing order
	void SortByPrize_IO(); //increasing order
	void PrintCatalogue();
};

#endif
