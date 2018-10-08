#include <iostream>

int main(int argc, char** argv)
{
	int numbers[10] = {1,2,3,4,5,6,7,8,9,10};

	int* pNumbers = numbers;

	std::cout << "numbers = " << numbers << std::endl;	//pointer to numbers array. numbers = pointer, numbers[0] = 1.
	std::cout << "pNumbers = " << pNumbers << std::endl;//pointer to the pointer of the number array. pNumbers = pointer, *pNumbers = 1, pnumber[0] = 1
	
	return 0;
	
}
