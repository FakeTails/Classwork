// Name: Joshua LaRocca

#include "Scheduler.cpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int choice = 0;			// int to hold the selection of the user.
	int apptTime = 0;		// int to hold the time of the appointment for later in the program.
	string input = "";		// string to hold the input from the user while the program is running.
	
	Scheduler myScheduler; 	// reference to the scheduler class.

	myScheduler.createDoctorList();		// create doctor list.
	myScheduler.createPatientList();	// create patient list.

	do
	{
		// output a menu.
		cout << "choose from the following options: " << endl;	
		cout << "1: List all patients" << endl;
		cout << "2: List all doctors" << endl;
		cout << "3: Look up patient by name" << endl;
		cout << "4: Look up doctor by name" << endl;
		cout << "5: Add appointment" << endl;
		cout << "6: Remove appointment" << endl;
		cout << "7: Check appointment" << endl;
		cout << "8: Write List of Patients to file" << endl;
		cout << "9: Write List of Doctors and their schedules to file" << endl;
		cout << "0: Exit" << endl;
		
		std::getline(std::cin, input); 	// get input from the user.
		choice = std::stoi(input);		// convert it into an int.
		
		
		switch (choice)
		{
			case 1: // list patients.
			{
				myScheduler.listPatients(); 
				break;
			}
			case 2: // list doctors.
			{
				myScheduler.listDoctors(); 
				break;
			}
			case 3: // Look up patient by name.
			{
				cout << "Please enter the name of the patient you would like to look up: ";
				std::getline(std::cin, input);
				cout << myScheduler.lookupPatient(input).toString() << endl; // output the result.
				break;
			}
			case 4: // Look up doctor by name.
			{
				cout << "Please enter the name of the doctor you would like to look up: ";
				std::getline(std::cin, input);
				cout << myScheduler.lookupDoctor(input).toString(1) << endl; // output the result.
				break;
			}
			case 5: // Add appointment.
			{
				cout << "Enter the name of the doctor to add an appointment to: "; 	// prompt for input.
				std::getline(std::cin, input); 										// get input.
				Doctor tempDoctor = myScheduler.lookupDoctor(input);				// use input for looking up.
				
				cout << "Enter the name of the patient to assign to an appointment: ";	// prompt for input.
				std::getline(std::cin, input);											// get input.
				Patient tempPatient = myScheduler.lookupPatient(input);					// use input for looking up.
				
				cout << "Enter the time of the appointment: (8 AM,9,10,11,12 PM,1,2,3 format of \"8\") ";	// prompt for input.
				std::getline(std::cin, input);																// get input.
				apptTime = std::stoi(input);																// convert input into an int.
				if (apptTime == 1 || apptTime == 2 || apptTime == 3  )										// determine if the int needs to be converted to military time.
				{
					apptTime += 12;																			// if so, add 12 for hours.
				}
				
				myScheduler.addAppointment(tempDoctor, tempPatient, apptTime);	// add the appointment with the above information.
				break;
			}
			case 6: // Remove appointment.
			{
				cout << "Enter the name of the doctor to clear an appointment from: ";	// prompt for input.
				std::getline(std::cin, input);											// get input.
				Doctor tempDoctor = myScheduler.lookupDoctor(input);					// use input for looking up.
								
				cout << "Enter the time of the appointment to clear: ";	// prompt for input.
				std::getline(std::cin, input);							// get input.
				apptTime = std::stoi(input);							// convert input into an int.
				if (apptTime == 1 || apptTime == 2 || apptTime == 3  )	// determine if the int needs to be converted to military time.
				{
					apptTime += 12;										// if so, add 12 for hours.
				}
				
				myScheduler.removeAppointment(tempDoctor, apptTime);	// remove the appointment with the above information.
				break;
			}
			case 7: // Check appointment
			{
				cout << "Enter the name of the doctor to check the appointment of: ";	// prompt for input.
				std::getline(std::cin, input);											// get input.
				Doctor tempDoctor = myScheduler.lookupDoctor(input);					// use input for looking up.
				
				cout << "Enter the time of the appointment to check: ";	// prompt for input.
				std::getline(std::cin, input);							// get input.
				apptTime = std::stoi(input);							// convert input into an int.
				if (apptTime == 1 || apptTime == 2 || apptTime == 3  )	// determine if the int needs to be converted to military time.
				{
					apptTime += 12;										// if so, add 12 for hours.
				}
				
				myScheduler.checkAppointment(tempDoctor, apptTime);		// remove the appointment with the above information.
				break;
			}
			case 8: // Write List of Patients  file
			{
				cout << "Enter a name for the patient text file: ";	// prompt for input.
				std::getline(std::cin, input);				// get input.
				myScheduler.createPatientTextFile(input);		// write the file
				cout << "file writing successful!" << endl;
				break;
			}
			case 9: // Write List of Doctors and their schedules to file
			{
				cout << "Enter a name for the doctor text file: ";	// prompt for input.
				std::getline(std::cin, input);				// get input.
				myScheduler.createDoctorTextFile(input);		// write the file
				cout << "file writing successful!" << endl;
				break;
			}
			case 0: // exit
			{
				break;
			}
			default: // error message.
			{
				cout << "Please enter a number between 1 - 0." << endl;
				break;
			}
		}
	}while(choice != 0);	
	
	return 0;
}
