// Name: Joshua LaRocca

#include "Patient.h"
#include <String>

Patient::Patient()
{
	name = "";
	age = 0;
	sex = "";
}

Patient::Patient(string name, int age, string sex)
{
	this->age = age;
	this->sex = sex;
	this->name = name;
}

string Patient::getName() { return name; }
int Patient::getAge() { return age; }
string Patient::getSex() { return sex; }

Patient::setName(string name) { this->name = name; }
Patient::setAge(int age) { this->age = age; }
Patient::setSex(string sex) { this->sex = sex; }

string Patient::toString()
{
	return "Name: " + name + ", age: " + std::to_string(age) + ", sex: " + sex;
}
