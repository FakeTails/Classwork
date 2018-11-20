// Name: Joshua LaRocca

#include "ItemForSale.h"

ItemForSale::ItemForSale()
{
	name = "";
	salePrice = 0;
	profit = 0;
}

ItemForSale::ItemForSale(string name, double salePrice, double profit)
{
	this->name = name;
	this->salePrice = salePrice;
	this->profit = profit;
}

string ItemForSale::getName() { return name; }
double ItemForSale::getSalePrice() { return salePrice; }
double ItemForSale::getProfit() { return profit; }
	
void ItemForSale::setName(string name) { this->name = name; }
void ItemForSale::setSalePrice(double salePrice) { this->salePrice = salePrice; } 
void ItemForSale::setProfit(double profit) { this->profit = profit; }
