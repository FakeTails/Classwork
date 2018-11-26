#include<iomanip>
#include<ios>
#include<iostream>

using namespace std;

int main()
{
	double num = 123.4567890;
	
	cout << setprecision(8) << "when n = 8: " << num << endl; // to a set precision 
	cout << setprecision(5) << "when n = 5: " << num << endl; // to a set precision
	cout << setprecision(2) << "when n = 2: " << num << endl; // to a set precision
	cout << "Number after the manipulations: " << num << endl;

	cout << fixed << "After fixed: " << num << endl; // to a fixed point, with the set precision from above.
	cout << "Number after after the fixed: " << num << endl;
	
	num = 31.42; // done to allow for illustration of scientific notation
	
	cout << scientific << setprecision(2) << num << endl; // scientific notation
	cout << "Number after the scientific: " << num << endl;
}
