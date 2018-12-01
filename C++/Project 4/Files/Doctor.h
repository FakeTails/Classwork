// Name: Joshua LaRocca

#include <IOStream>
#include <vector>
#include "Patient.h"

using std::string;

#ifndef DOCTOR_H_
#define DOCTOR_H_

class Doctor
{
private:		
    string name;
    int age;
    string specialty;
    std::vector<Patient> schedule = std::vector<Patient>(8, {"Open", 0, "Other"});
public:
    Doctor();
    
    Doctor(string name, int age, string specialty);
    
    string getName();
    int getAge();
    string getSpecialty();
    Patient getSchedule(int);
    
    setName(string name);
    setAge(int age);
    setSpecialty(string specialty);
    setSchedule(Patient, int);
	
    string toString(int);
};

#endif
