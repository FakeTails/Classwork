#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	char string1[15] = "James Bond";
	char string2[15] = "Bond";
	char string3[15];
	char* subStr = ""; // or NULL or 0
	char string4[15];
	char string5[15];
	char string6[15];
	char string7[35] = "The name is Bond, James Bond!";
	char* subStr2 = ""; // or NULL or 0.
	char* subStr3 = ""; // or NULL or 0.
	char* subStr4 = ""; // or NULL or 0.
	
	subStr = &string1[6];
	
	if (strchr(string1,'J') != NULL) // if 'j' exists in string 1
	{
		subStr2 = strchr(string1, 'J'); // pointsto the first 'J'
		strcpy(string4, subStr2);	//string4 is now "James Bond"
	}
	
	cout << "String 4 is: "<< string4 << endl;
	
	subStr4 = strstr(string1, "Bond");
	if(subStr != NULL)
	{
		strcpy(string6, string4);
	}
	
	cout << "String 6 is: " << string6 << endl; 
	
	
	if(strcmp(subStr, string2) == 0)
	{
		cout << "Strings are the same." << endl;
	}
	
	strcpy(string3, subStr);	// destination then source.
	cout << "String 3 is: " << string3 << endl;
	
	return 0;
}
