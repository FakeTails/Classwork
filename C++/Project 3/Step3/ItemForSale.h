// Name: Joshua LaRocca

#include <IOStream>
#include <String>

using std::string;

#ifndef ITEMFORSALE_H_
#define ITEMFORSALE_H_

class ItemForSale
{
	private:
		string name;
		double salePrice; // changed name from cost to salePrice, changed in every location to reflect this.
		double profit;
		
	public:
	ItemForSale();
	ItemForSale(string name, double salePrice, double profit);

	string getName();
	double getSalePrice();
	double getProfit();
	
	void setName(string name);
	void setSalePrice(double salePrice);
	void setProfit(double profit);
};

#endif
