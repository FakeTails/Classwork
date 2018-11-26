// Name: Joshua LaRocca

#include "ItemForSale.cpp"
#include "Transaction.cpp"
#include <String>

using std::cout;
using std::cin;
using std::endl;

void SummaryOfTransactions(Transaction transactions[], ItemForSale items[], int mode)
{
	system("CLS");
	double totalProfit = 0; // to hold profit for output.
	int choice; // to hold user input.
	do
	{
		cout << "Please choose a type of sort to do on the transactions: " << endl;
		cout << "1: By ID" << endl;
		cout << "2: By item names (alphabetically)" << endl;
		cout << "3: By increasing order of profit" << endl;
		cin >> choice;
		if(choice < 1 || choice > 3)
		{
			cout << "You entered a number that isn't on the menu, please try again." << endl;
		}
	}while (choice < 1 || choice > 3); 
	
	switch(choice)
	{
		case 1: // Sort by ID.
			{
				int i, j;
				Transaction temp;
				
				for (i = 1; i < 10; ++i) 
				{
				   j = i;
				   while (j > 0 && transactions[j].getID() < transactions[j - 1].getID()) // sort based on ID
				   {
				      temp = transactions[j];
				      transactions[j] = transactions[j - 1];
				      transactions[j - 1] = temp;
				      --j;
				   }
				}
				break;
			}
			case 2: // Sort item names (alphabetically).
			{
				int i, j;
				Transaction temp;
				
				for (i = 1; i < 10; ++i) 
				{
				   j = i;
				   while (j > 0 && transactions[j].getItem().getName() < transactions[j - 1].getItem().getName()) // sort based on name
				   {
				      temp = transactions[j];
				      transactions[j] = transactions[j - 1];
				      transactions[j - 1] = temp;
				      --j;
				   }
				}
				break;
			}
			case 3: // Sort By increasing order of profit.
			{
				int i, j;
				Transaction temp;
				
				for (i = 1; i < 10; ++i) 
				{
				   j = i;
				   while (j > 0 && transactions[j].getItem().getProfit() < transactions[j - 1].getItem().getProfit()) //sort based on profit.
				   {
				      temp = transactions[j];
				      transactions[j] = transactions[j - 1];
				      transactions[j - 1] = temp;
				      --j;
				   }
				}
				break;
			}
	}
	
	// output all transacations in new sorted order.
	for (int i = 0; i < 10; i++)
	{
		if (!transactions[i].getID() == 0)
		{
			transactions[i].ToString();
		}
	}
	
	if (mode == 0) // mode is set by passed int.
	{
		// calculate total profit for day.
		for (int i = 0; i < 10; i++)
		{
			if (!transactions[i].getID() == 0)
			{
				totalProfit += transactions[i].getItem().getProfit();
			}
		}
		cout << endl << "Total profit for the day: " << totalProfit << "." << endl;
		
		cout << endl; // new line.
		
		// output average profit.
		for (int i = 1; i < 6; i++)
		{
			cout << "Average profit for " << items[i].getName() << ": " << items[i].getProfit() << "." << endl;
		}
		
		cout << endl; // new line.
		
		// output profit per item.
		for (int i = 1; i < 6; i++)
		{
			double tempTotalProfit = 0; // double to hold the values for profit per item.
			
			for (int j = 0; j < 10; j++)
			{
				if (items[i].getName() == transactions[j].getItem().getName())
				{
					tempTotalProfit += items[i].getProfit();
				}
			}
			if (tempTotalProfit == 0)
			{
				cout << "There were no sales for " << items[i].getName() << " today." << endl;
			}
			else
			{
				cout << "The total profit for " << items[i].getName() << " is: " << tempTotalProfit << "." << endl;
			}
		}
		
		cout << endl; // new line.
	}
	
}

void processTransacation(Transaction transactions[], ItemForSale items[])
{
	int hour, minute, second, choice; // create variables needed to create the transaction, and choice.
	bool writen = false; // bool to determine if what you're trying to add has been added yet or not.
		
	cout << "Please enter the hour that the item was purchased: ";
	cin >> hour;
	while (hour < 0 || hour > 23) // input validation.
	{ 
	cout << "You may only enter a real hour (0 - 23), please enter again: "; 
	cin >> hour; 
	}
	
	cout << "Please enter the minute that the item was purchased: ";
	cin >> minute;
	while (minute < 0 || minute > 59) // input validation.
	{ 
	cout << "You may only enter a real minute (0 - 59), please enter again: "; 
	cin >> minute;
	}
	
	cout << "Please enter the second that the item was purchased: ";
	cin >> second;
	while (second < 0 || second > 59) // input validation.
	{ 
	cout << "You may only enter a real second (0 - 59), please enter again: "; 
	cin >> second; 
	}
	
	// output menu for choice.
	do
	{
		cout << "Choose the item that was sold:" << endl;
		cout << "1: Flowers" << endl;
		cout << "2: Cookies" << endl;
		cout << "3: Eggs" << endl;
		cout << "4: Milk" << endl;
		cout << "5: Red Dead Redemption 2" << endl;
		cin >> choice;
		if (choice < 1 || choice > 6) // input validation.
		{
			cout << "You entered a number that isn't on the menu, please try again." << endl;
		}
	}while (choice < 1 || choice > 6); 
	
	// add the desiered item to the array in an empty location.
	for (int i = 0; i < 10; i++)
	{
		if (transactions[i].getID() == 0 && writen == false)
		{
			transactions[i] = Transaction(hour, minute, second, items[choice]); // add the transaction.
			writen = true;
		}
	}
	
	cout << endl; // new line.
	
}

void voidTransacation(Transaction transactions[], ItemForSale items[])
{
	int ID;	// create an int for ID.
	bool wasVoided = false; // bool to determin if the void was completed.
	cout << "Choose from the list above which ID you would like to void: ";
	cin >> ID;
	
	// set everything to 0 to tell the system that there is nothing there.
	for (int i = 0; i < 10; i++)
	{
		if (transactions[i].getID() == ID) 
		{
			transactions[i].setHour(0);
			transactions[i].setMinute(0);
			transactions[i].setSecond(0);
			transactions[i].setItem(items[0]);
			transactions[i].setID(0);
			wasVoided = true;
		}
	}
	
	system("CLS");									// clean up the screen.
	
	if (wasVoided == false)
	{
		cout << "No such transaction." << endl << endl;
	}
	else
	{
		cout << "Transaction voided." << endl << endl;
	}
}

void menuDisplay(Transaction transactions[], int currentTransaction, ItemForSale items[])
{
	int choice; // int to hold user choice.
	
	do
	{
		// output a menu.
		cout << "choose from the following options: " << endl;	
		cout << "1: Add a transaction" << endl;
		cout << "2: Void a transaction" << endl;
		cout << "3: Print the daily Summary" << endl;
		cout << "4: Exit" << endl;
		
		cin >> choice;
		
		
		switch (choice)
		{
			case 1: // Add a transaction.
			{
				if (currentTransaction == 10) // if you reached the end of the array...
				{
					cout << "There are already 10 transacations, either void a transaction, " << endl << "or print the summary and be done with your day." << endl; // tell them.
				}
				else
				{
					processTransacation(transactions, items);		// call the function to add the transaction.
					currentTransaction++;							// increment the current transaction to keep track for this menu.
					system("CLS");									// clean up the screen.
					cout << "Transaction added." << endl << endl;	// tell the user it was successful.
				}
				break;
			}
			case 2: // Void a transaction.
			{
				if (currentTransaction == 0) // if you have noting in the array...
				{
					cout << "There aren't any transacations to void. Add a transacation before voiding please." << endl; // tell them.
				}
				else
				{
					cout << "Outputting a summary of current transacations first: " << endl; // output the menu for the transacations so you know what to choose from.
					
					SummaryOfTransactions(transactions, items, 1); // so that you can see the ID's.
					
					voidTransacation(transactions, items);	// call the void transaction function.
					currentTransaction--;					// decrement the current transacation since you removed from the array.
				}
				break;
			}
			case 3: // Print the daily Summary.
			{
				SummaryOfTransactions(transactions, items, 0);
			}
			case 4: // exit.
			{
				break;	
			}
			default:
			{
				cout << "You entered a number that isn't on the menu, please try again." << endl;
				break;
			}
		}
	}while(choice != 4);	
}


int main()
{
	// create an array to hold all transactions.
	Transaction transactions[] { Transaction(), Transaction(), Transaction(), Transaction(), Transaction(), Transaction(), Transaction(), Transaction(), Transaction(), Transaction() };
	int currentTransaction = 0; // create an int to tell the system how many elements are in use within the array.
	// create an array to hold items for sale.
	ItemForSale items[] { {"none", 0, 0}, {"Flowers", 1.11, .57}, {"Cookies", 9.99, 4.49}, {"Eggs", 2.18, .97}, {"Milk", 4.12, 2.15}, {"Red Dead Redemption 2", 59.99, 20.95} };

	menuDisplay(transactions, currentTransaction, items); // display the menu.
	
	return 0;	
}
