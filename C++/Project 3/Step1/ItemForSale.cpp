// Name: Joshua LaRocca

#include "ItemForSale.h"
#include <String>

ItemForSale::ItemForSale()
{
	name = "";
	cost = 0;
	profit = 0;
}

ItemForSale::ItemForSale(string name, double cost, double profit)
{
	this->name = name;
	this->cost = cost;
	this->profit = profit;
}

String ItemForSale::getName() { return name; }
double ItemForSale::getCost() { return cost; }
double ItemForSale::getProfit() { return profit; }
	
void ItemForSale::setName(string name) { this->name = name; }
void ItemForSale::setCost(double cost) { this->cost = cost; }
void ItemForSale::setProfit(double profit) { this->profit = profit; }
