#include <iostream>

int main()
{

int sunday = 0;
int monday = 1;
int tuesday = 2;
int wednesday = 3;
int thursday = 4;
int friday = 5;
int saturday = 6;

int daysOfWeek = 0;

std::cout << "Please enter what todays date is based on these numbers:" << std::endl << "0 stands for sunday" << std::endl <<
"1 stands for monday" << std::endl << "2 stands for tuesday" << std::endl << "3 stands for wednesday" << std::endl << "4 stands for thursday" << std::endl <<
"5 stands for friday" << std::endl << "6 stands for saturday" << std::endl;
std::cin >> daysOfWeek;
if (daysOfWeek % 6 == 0)
{
    std::cout << "today is saturday!";
}
else
{
    if (daysOfWeek % 5 == 0)
    {
        std::cout << "today is friday!";
    }
    else
    {
	if (daysOfWeek % 4 == 0)
	{
	    std::cout << "today is thursday!";	    
	}
	else
	{
	    if (daysOfWeek % 3 == 0)
	    {
		std::cout << "today is wednesday";
	    }
	    else
	    {
		if (daysOfWeek % 2 == 0)
		{
		    std::cout << "today is tuesday";
		}
		else
		{
		    if (daysOfWeek % 1 == 0)
		    {
			std::cout << "today is monday";
		    }
		    else
		    {
			std::cout << "today is sunday";
		    }
		}
	    }
	}
    }
}
}
