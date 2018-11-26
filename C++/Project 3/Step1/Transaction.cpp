// Name: Joshua LaRocca

#include "Transaction.h"
#include <String>

Transaction::Transaction()
{
	hour = 0;
	minute = 0;
	second = 0;
	item = ItemForSale(none, 0, 0);
	ID = generateID();
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

string Transaction::ToString()
{
	return  "Time: " + std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second) + ". Transacation ID: " + std::to_string(ID) + ", Item name: " + item.getName() + ", selling price: " 
	+ std::to_string(item.getSalePrice()) + ", profit on item: " + std::to_string(item.getProfit()) + ".";
}
