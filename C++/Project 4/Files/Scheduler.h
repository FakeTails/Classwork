// Name: Joshua LaRocca

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <vector>
#include "Doctor.h"
#include "Patient.h"

class Scheduler
{
private:
	std::vector<Doctor> doctorList = std::vector<Doctor>();
	std::vector<Patient> patientList = std::vector<Patient>();
	
public:	
	listPatients();
	listDoctors();

	Patient lookupPatient(string);	
	Doctor lookupDoctor(string);

	addAppointment(Doctor, Patient, int);
	removeAppointment(Doctor, int);
	checkAppointment(Doctor, int);
	
	createDoctorList();
	createPatientList();
	
	createDoctorTextFile(string);
	createPatientTextFile(string);	
};

#endif
