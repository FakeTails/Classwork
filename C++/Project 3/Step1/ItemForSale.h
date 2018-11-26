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
		double cost;
		double profit;
		
	public:
	ItemForSale();
	ItemForSale(string name, double cost, double profit);

	string getName();
	double getCost();
	double getProfit();
	
	void setName(string name);
	void setCost(double cost);
	void setProfit(double profit);
};

#endif
