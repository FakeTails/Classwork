#include <iostream>

int main()
{
	double userNum;
	double truncatedNum;
	
	std::cout << "Please input a float number with more than three digits after the decimal point:";
	std::cin >> userNum;
	
	truncatedNum = userNum * 100;
	
	truncatedNum = (int)truncatedNum;
	
	truncatedNum /= 100;
	
	std::cout << "\nThe truncated result of " << userNum << " is " << truncatedNum << "."; 
	
	return 0;
}
