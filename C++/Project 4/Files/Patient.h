// Name: Joshua LaRocca

#include <IOStream>

using std::string;

#ifndef PATIENT_H_
#define PATIENT_H_

class Patient
{
private:
    string name;
    int age;
    string sex;
public:
    Patient();
    
    Patient(string name, int age, string sex);
    
    string getName();
    int getAge();
    string getSex();
    
    setName(string name);
    setAge(int age);
    setSex(string sex);
	
    string toString();
};

#endif
