// Name: Joshua LaRocca

#include "Transaction.h"

Transaction::Transaction()
{
	hour = 0;
	minute = 0;
	second = 0;
	item = ItemForSale("none", 0, 0); // added quotation marks for making the item.
	ID = 0;	// set to 0 now to indicate empty.
}

Transaction::Transaction(int hour, int minute, int second, ItemForSale item)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
	this->item = item;
	ID = generateID();
}

int Transaction::generateID()
{
	return rand() % 100 + 1;
}

int Transaction::getHour() { return hour; }
int Transaction::getMinute() { return minute; }
int Transaction::getSecond() { return second; }
int Transaction::getID() { return ID; }
ItemForSale Transaction::getItem() { return item; }

void Transaction::setHour(int hour) { this->hour = hour; }
void Transaction::setMinute(int minute) { this->minute = minute; }
void Transaction::setSecond(int second) { this->second = second; }
void Transaction::setItem(ItemForSale item) { this->item = item; }
void Transaction::setID(int ID) { this->ID = ID; } // decided to create this in the end for when voiding the transaction.

void Transaction::ToString() // changed from string to void because it doesn't really need to return anything.
{	
	// the changed name from cost to salePrice reflected here.
	std::cout << "Time: " << hour << ":" << minute << ":" << second << ". Transacation ID: " << ID << ", Item name: " << item.getName() << "," << std::endl 
	<< "selling price: " << item.getSalePrice() << ", profit on item: " << item.getProfit() << "." << std::endl;
}
