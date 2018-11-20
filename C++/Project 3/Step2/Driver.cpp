// Name: Joshua LaRocca

#include "ItemForSale.cpp"
#include "Transaction.cpp"
#include <String>

using std::cout;
using std::cin;
using std::endl;

void processTransacation(Transaction transactions[], int element, ItemForSale items[])
{
	int hour, minute, second, choice;
	ItemForSale tempItem;
	cout << "Please enter the hour that the item was purchased: ";
	cin >> hour;
	cout << "Please enter the minute that the item was purchased: ";
	cin >> minute;
	cout << "Please enter the hour that the item was purchased: ";
	cin >> second;
	
	do
	{
		cout << "Choose the item that was sold:" << endl;
		cout << "1: Flowers" << endl;
		cout << "2: Cookies" << endl;
		cout << "3: Eggs" << endl;
		cout << "4: Milk" << endl;
		cout << "5: Red Dead Redemption 2" << endl;
		cin >> choice;
		if (choice < 1 || choice > 6)
		{
			cout << "You entered a number that isn't on the menu, please try again." << endl;
		}
	}while (choice < 1 || choice > 6); 
	
	
	transactions[element] = Transaction(hour, minute, second, items[choice]);
}

void voidTransacation(Transaction transactions[], int currentTransaction, ItemForSale items[])
{
	int ID;
	cout << "Choose from the list above which ID you would like to void: ";
	cin >> ID;
	
	for (int i = 0; i < currentTransaction; i++)
	{
		if (transactions[i].getID() == ID)
		{
			transactions[i].setHour(0);
			transactions[i].setMinute(0);
			transactions[i].setSecond(0);
			transactions[i].setItem(items[0]);
		}
	}
}

void menuDisplay(Transaction transactions[], int currentTransaction, ItemForSale items[])
{
	int choice;
	
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
				if (currentTransaction > 9)
				{
					cout << "There are already 10 transacations, either void a transaction, or print the summary and be done with your day." << endl;
				}
				else
				{
					processTransacation(transactions, currentTransaction, items);
					currentTransaction++;
				}
				break;
			}
			case 2: // Void a transaction.
			{
				if (currentTransaction == 0)
				{
					cout << "There aren't any transacations to void. Add a transacation before voiding please." << endl;
				}
				else
				{
					//SummaryOfTransacations(); // so that you can see the ID's.
					
					voidTransacation(transactions, currentTransaction, items);
					currentTransaction--;
				}
				break;
			}
			case 3: // Print the daily Summary.
			{
				//SummaryOfTransactions();
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
	Transaction transactions[10];
	int currentTransaction = 0;
	ItemForSale items[] { {"none", 0, 0}, {"Flowers", 1.00, 1.00}, {"Cookies", 9.99, 4.50}, {"Eggs", 2.18, .97}, {"Milk", 4.12, 2.15}, {"Red Dead Redemption 2", 59.99, 20.95} };

	menuDisplay(transactions, currentTransaction, items);
	
	return 0;	
}
