#include<iostream>
#include<fstream>
#include <cstdlib>
using namespace std;

int main(){
	ofstream outFS; // output file stream
	int fileNum; // File data
	
	// Open file to write to
	cout << "Opening file myOutputFile.txt" << endl;
	outFS.open("myOutputFIle.txt", ios::app); // difference is here, ios::app (append)
	
	// check to see if the file exists
	if(!outFS.is_open())
	{
		cout << "could not open the file myOutputFile.txt" << endl;
		return EXIT_FAILURE;
	}
	
	// Write to the file
	cout << "Writing to file..." << endl;
	outFS << "appended" << endl;
	outFS << 1.345 << endl;
	outFS << "text" << endl;
	
	// done with file so close it.
	cout << "Closing file myOutputFile.txt" << endl;
	outFS.close();
	
	return EXIT_SUCCESS;
}
