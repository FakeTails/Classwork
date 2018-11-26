#include<iostream>
#include<fstream>
#include <cstdlib>
#include<iomanip>
using namespace std;

int main(){
	ifstream inFS; // Input file stream
	int fileNum; // File data
	
	// Open file to read
	cout << "Opening file myInputFile.txt" << endl;
	inFS.open("myInputFile.txt");
	
	if(!inFS.is_open()) // if it didn't open...
	{
		cout << "could not open file myInputFile.txt" << endl;
		return EXIT_FAILURE;
	}
	
	// read file and print numbers to output.
	cout << "Reading and printing numbers." << endl;
	
	while(!inFS.eof()) // while NOT at the end of the file...
	{
		inFS >> fileNum;
		if(!inFS.fail()) // if you did NOT fail..
		{
			cout << "num: " << fileNum << endl;
		}
		else if (!inFS.eof()) // if you are NOT at the end of the file..
		{
			cout << "Error reading number from file" << endl;
		}
	}
	
	// dont with file so close it.
	cout << "Closing file myInputFile.txt" << endl;
	inFS.close();
	
	return EXIT_SUCCESS;
}
