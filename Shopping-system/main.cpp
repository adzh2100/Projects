#include "Product.h"
#include "Account.h"
#include "Catalogue.h"
#include "Cart.h"
#include "DataBase.h"
#include "Printer.h"
#include "Jacket.h"
#include "Phone.h"
#include "Customer.h"
#include "Seller.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DataBase database;
	Catalogue catalogue;
	Product* first = new Phone("Iphone X", 2199.97, 5.8, 256,10);
	Product* second = new Printer("Xerox Phaser 3020BI", 140.26, "A4", 20,2);
	Product* third = new Jacket("GUESS JEANS Leather Jacket", 109.99, 'M',12);
	Product* fourth = new Phone("Samsung Galaxy", 1249.98, 6.1, 128, 7);
	database.addProduct(first);
	database.addProduct(second);
	database.addProduct(third);
	database.addProduct(fourth);
	catalogue.addProduct(first);
	catalogue.addProduct(second);
	catalogue.addProduct(third);
	catalogue.addProduct(fourth);

	Account* customer = new Customer("ivan.ivanov", "12345689", "ul. \"Gotse Delchev\" 25", "0897687876");
	database.Register(customer);
	database.LogIn("ivan.ivanov","12345689");
	customer->printInfo();
	
	catalogue.SortByPrize_IO();
	catalogue.PrintCatalogue();

	dynamic_cast<Customer*>(customer)->addToCart(first);
	dynamic_cast<Customer*>(customer)->addToCart(second);
	dynamic_cast<Customer*>(customer)->viewCart();
	dynamic_cast<Customer*>(customer)->removeFromCart(first->getId());
	dynamic_cast<Customer*>(customer)->Purchase();
	
	catalogue.FilterByCategory(Category::ELECTRONICS);
	database.LogOut(customer);

	Account* seller = new Seller("ivaylo.petrov", "mypassword", "ul. \"Hristo Smirnenski\" 9", "0896559025");
	database.Register(seller);
	database.LogIn("ivaylo.petrov", "mypassword");

	Product* myproduct = new Jacket("DENIM JACKET", 68.99, 'S', 1);
	dynamic_cast<Seller*>(seller)->add(myproduct);
	dynamic_cast<Seller*>(seller)->add(first);
	database.addProduct(myproduct); //doing this manually because Seller doesn't know about DataBase and Catalogue classes
	catalogue.addProduct(myproduct);
	seller->printInfo();
	dynamic_cast<Seller*>(seller)->remove(myproduct->getId());
	seller->printInfo();


	delete first;
	delete second;
	delete third;
	delete fourth;
	delete customer;
	delete seller;
	delete myproduct;
}
