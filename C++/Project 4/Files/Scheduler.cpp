// Name: Joshua LaRocca

#include<iostream>
#include<fstream>
#include <cstdlib>
#include <String>

#include "Scheduler.h"

#include "Doctor.cpp"
#include "Patient.cpp"

Scheduler::listPatients()
{
	for (int i = 0; i < patientList.size(); i++)
	{
		std::cout << patientList.at(i).toString() << std::endl; 
	}
}
 Scheduler::listDoctors()
{
	for (int i = 0; i < doctorList.size(); i++)
	{
		std::cout << doctorList.at(i).toString(0) << std::endl; 
	}
}

Patient Scheduler::lookupPatient(string patientName)
{
	for (int i = 0; i < patientList.size(); i++)
	{
		if (patientList.at(i).getName() == patientName)
		{
			return patientList.at(i);
		}
	}
}

Doctor Scheduler::lookupDoctor(string doctorName)
{
	for (int i = 0; i < doctorList.size(); i++)
	{
		if (doctorList.at(i).getName().compare(doctorName) == 0)
		{
			return doctorList.at(i);
		}
	}
}


Scheduler::addAppointment(Doctor doctor, Patient patient, int timeSlot)
{
	int element = 0;
	
	for (int i = 0; i < doctorList.size(); i++)
	{
		if (doctorList.at(i).getName().compare(doctor.getName()) == 0)
		{
			element = i;
		}
	}
	
	if (doctorList.at(element).getSchedule(timeSlot).getName().compare("Open") == 0)
	{
		doctorList.at(element).setSchedule(patient, timeSlot);
	}
	else
	{
		std::cout << "This time slot is already full. Please try another." << std::endl;
	}
}

Scheduler::removeAppointment(Doctor doctor, int timeSlot)
{
	Patient openTimeSlot("Open", 0, "Other");
	
	int element = 0;
	
	for (int i = 0; i < doctorList.size(); i++)
	{
		if (doctorList.at(i).getName().compare(doctor.getName()) == 0)
		{
			element = i;
		}
	}
	
	doctorList.at(element).setSchedule(openTimeSlot, timeSlot);
}

Scheduler::checkAppointment(Doctor doctor, int timeSlot)
{
	int element = 0;
	
	for (int i = 0; i < doctorList.size(); i++)
	{
		if (doctorList.at(i).getName().compare(doctor.getName()) == 0)
		{
			element = i;
		}
	}
	
	std::cout << doctorList.at(element).getSchedule(timeSlot).getName() << std::endl;
}

Scheduler::createDoctorList()
{
	std::ifstream inFS; // Input file stream
	string firstName, lastName, fullName, specialty;
	int age;
	
	inFS.open("doctors.txt");
	
	if(!inFS.is_open()) // if it didn't open...
	{
		std::cout << "could not open file doctors.txt" << std::endl;
		return EXIT_FAILURE;
	}
	
	while(!inFS.eof()) // while NOT at the end of the file...
	{
		inFS >> firstName;
		inFS >> lastName;
		inFS >> age;
		inFS >> specialty;
		
		fullName = firstName + " " + lastName;
		
		Doctor newDoctor(fullName, age, specialty);
		
		doctorList.push_back(newDoctor);
	}
		
	// done with file so close it.
	inFS.close();
}

Scheduler::createPatientList()
{
	std::ifstream inFS; // Input file stream
	string firstName, lastName, fullName, sex;
	int age;
	
	inFS.open("patients.txt");
	
	if(!inFS.is_open()) // if it didn't open...
	{
		std::cout << "could not open file patients.txt" << std::endl;
		return EXIT_FAILURE;
	}
	
	while(!inFS.eof()) // while NOT at the end of the file...
	{
		inFS >> firstName;
		inFS >> lastName;
		inFS >> age;
		inFS >> sex;
		
		fullName = firstName + " " + lastName;
		
		Patient newPatient(fullName, age, sex);
		
		patientList.push_back(newPatient);
	}
		
	// done with file so close it.
	inFS.close();
}

Scheduler::createDoctorTextFile(string fileName)
{
	std::ofstream outFS; // output file stream
	
	// Open file to write to
	outFS.open(fileName + ".txt");
	
	// Write to the file
	outFS << "List of Doctors:" << std::endl;
	for (int i = 0; i < doctorList.size(); i++)
	{
		outFS << doctorList.at(i).toString(1) << std::endl;
	}
	
	// done with file so close it.
	outFS.close();
}

Scheduler::createPatientTextFile(string fileName)
{
	std::ofstream outFS; // output file stream
	
	// Open file to write to
	outFS.open(fileName +".txt");
	
	// Write to the file
	outFS << "List of Patients:" << std::endl;
	for (int i = 0; i < patientList.size(); i++)
	{
		outFS << patientList.at(i).toString() << std::endl;
	}
	
	// done with file so close it.
	outFS.close();
}
