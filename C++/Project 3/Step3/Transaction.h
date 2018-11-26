// Name: Joshua LaRocca

#include <IOstream>
#include <String>
#include "ItemForSale.h"

using std::string;

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

class Transaction
{
	private:
		int hour;
		int minute;
		int second;
		int ID;
		ItemForSale item;
		
	public:
	Transaction();
	Transaction(int hour, int minute, int second, ItemForSale item);

	int generateID();

	int getHour();
	int getMinute();
	int getSecond();
	int getID();
	ItemForSale getItem();
	
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);
	void setItem(ItemForSale item);
	void setID(int ID);	// decided to create this in the end for when voiding the transaction.
	
	void ToString(); // changed to void because it didn't REALLY need to return something, just be called.
};

#endif
