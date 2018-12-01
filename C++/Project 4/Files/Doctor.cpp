// Name: Joshua LaRocca

#include "Doctor.h"
#include <String>

Doctor::Doctor()
{
	name = "";
	age = 0;
	specialty = "";
}

Doctor::Doctor(string name, int age, string specialty)
{
	this->name = name;
	this->age = age;
	this->specialty = specialty;
}

string Doctor::getName() { return name; }
int Doctor::getAge() { return age; }
string Doctor::getSpecialty() { return specialty; }
Patient Doctor::getSchedule(int timeSlot) { return schedule[timeSlot - 8]; }

Doctor::setName(string name) { this->specialty = name; }
Doctor::setAge(int age) { this->specialty = age; }
Doctor::setSpecialty(string specialty) { this->specialty = specialty; }
Doctor::setSchedule(Patient patient, int timeSlot) 
{ 
	schedule.at(timeSlot - 8) = patient; 
}

string Doctor::toString(int num)
{
	if (num == 0)
	{
		return "Name: " + name + ", age: " + std::to_string(age) + ", specialty: " + specialty;
	}
	else
	{
		return "Name: " + name + ", age: " + std::to_string(age) + ", specialty: " + specialty +
		",\nSchedule: 8 AM: " + schedule[0].getName() + ", 9 AM: " + schedule[1].getName() + 
		",\n10 AM: " + schedule[2].getName() + ", 11 AM: " + schedule[3].getName() + ", 12 PM: " + schedule[4].getName() + 
		",\n1 PM: " + schedule[5].getName() + ", 2 PM: " + schedule[6].getName() + ", 3 PM: " + schedule[7].getName() + ".";
	}
	
}
