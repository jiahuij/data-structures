// File: appointmentTest.cpp

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Appointment.h"

using namespace std;

#define INITIAL_DB_SIZE 3



//This function merges two vectors into one vector.
bool mergeTwoSortedVectors(vector<Appointment> & vecA, vector< Appointment > & vecB, vector< Appointment > & vecC){

	//To store the number of the size of the vectors
	int vectAsize, vectBsize, vectCsize;

	// to keep counting of the number of vector already merged into the third vector
	int countA = 0, countB = 0, countC = 0;


	// for checking if the vectors passed in is in ascending order
	bool sortedA = true;
	bool sortedB = true;


	// to resize the size of the third vector by adding the size of two passed in vectors together
	vectAsize = vecA.size();
	vectBsize = vecB.size();
	vectCsize = vectAsize + vectBsize;
	vecC.resize(vectCsize);


	//Check if the the vecA is in ascending order. 
	for (int i = 0; i < vecA.size() - 1; i++){

		if (vecA[i] > vecA[i + 1]){
			sortedA = false;
			break;
		}

	}

	//Check if the the vecB is in ascending order.
	for (int i = 0; i < vecB.size() - 1; i++){

		if (vecB[i]> vecB[i + 1]){
			sortedB = false;
			break;
		}

	}

	// If either of the passed in vector is not in ascending order, just return false.
	if (sortedA == false || sortedB == false){
		return false;
	}

	else{
		// if both passed in vector is in ascending order, compare the very first numbers in both vectors and save the 
		// smaller one into the third vector. Keep on doing the same thing to the next number of the vector until
		// all the numbers in both vector in saved in.


		while (countC != vecC.size()){
			//Keep on looping until all vectors in both vectors is saved.



			if (countA != vecA.size() && countB != vecB.size()){
				// Keep on checking if vector is going out of range

				if (vecA[countA] < vecB[countB]){
					// if the number in vecA is smaller, save the number into the thir vector and undate the counters for both vecA and vecC.

					vecC[countC] = vecA[countA];
					countA++;
					countC++;


				}

				else if (vecA[countA] >= vecB[countB]){
					// if the number in vecB is smaller, save the number into the thir vector and undate the counters for both vecB and vecC.

					vecC[countC] = vecB[countB];
					countB++;
					countC++;

				}


			}

			// If All the number in vecA had been saved in the third vector, save the remaining number in vecB into the third vector
			if (countA == vecA.size()){

				vecC[countC] = vecB[countB];
				countB++;
				countC++;

			}

			// If All the number in vecB had been saved in the third vector, save the remaining number in vecA into the third vector
			else if (countB == vecB.size()){

				vecC[countC] = vecA[countA];
				countA++;
				countC++;


			}


		}

		return true;

	}
}


//This function sorts the numnbers in a vector in ascending order
bool mergeSort(vector<Appointment> & vecToSort){
	int counter = 0;

	// If the vector passed in has only one number, just return 
	if (vecToSort.size() == 1){

		return true;
	}
	else if (vecToSort.size() == 2){
		//If the vector passed in has only two numbers, check if the first number is larger than the second number.
		// if the first number is larger, swap the numbers and return.

		if (vecToSort[0] > vecToSort[1])
			std::swap(vecToSort[0], vecToSort[1]);

		return true;

	}

	else if (vecToSort.size() > 2){
		// if the passed in vector has more than three numbers in it, divid the vectors passed in into two vector and keep on dividing until
		// there is only two numbers in the vector and call the function itself to check if the first number is larger or smaller.


		vector<Appointment>  vec1, vec2;
		// object vectors for dividing the passed in vector

		// set the size of vec1 to half of the size of the passed in vector 
		vec1.resize(vecToSort.size() / 2);

		// set the other size of vec2 to the half of the half of the size of the passed in vector 
		vec2.resize(vecToSort.size() - (vecToSort.size() / 2));


		// save the vec1 into the passed in vector
		for (int i = 0; i < vec1.size(); i++){
			vec1[i] = vecToSort[counter];
			counter++;
		}

		// save the vec2 to the passed in vector
		for (int i = 0; i < vec2.size(); i++){
			vec2[i] = vecToSort[counter];
			counter++;
		}

		// call the mergeTwoSortedVectors functiont o check if both vec1 and vec2 is in order. 
		//if they are not in order, call the function itself to divid the vector again
		if (!mergeTwoSortedVectors(vec1, vec2, vecToSort)){

			mergeSort(vec1);
			mergeSort(vec2);
			mergeTwoSortedVectors(vec1, vec2, vecToSort);
		}
	}


}


// The main function provides a menu of functions for making appointments.
void main()
{
	vector<Appointment> appointmentDB;// creating a vector to store appointment informations
	Appointment aAppointment;// creating local appointment object
	string  aFirstName, aLastName, fileName;// to store the firstname, lastname, and a file name from user input  
	DateType  dBegin, dEnd, exampleDate, referenceD;// dBegin: to store the beginning date of a range of date
	                                                // dEnd: to store the ending date of a range of date
	                                                // exampleDate: to store a date from user input as example date for searching use
	                                                // referenceD:  to store a date as an reference of a sunday.
	ifstream fin; // to out put data to a file
	ofstream fout; // to in put data from a file
	int  numAppointmentRecords = 0, index = 0;   // numAppointmentRecords: to keep track of how many appintments in the vector
	                                             // index: use to access particular member in the vector
	char userChoice; // to store user input of choice for menu
	bool inMenu = true;


	while (inMenu){
		
		//Display menu
		cout << "********************************** Menu **********************************" << endl;
		cout << "*                                                                        *" << endl;
		cout << "*  K : Make an appointment.                                              *" << endl;
		cout << "*  R : Clear all appointments and read new appointments in from a file.  *" << endl;
		cout << "*  D : Display all appointments.                                         *" << endl;
		cout << "*  M : Change information of an appointment.                             *" << endl;
		cout << "*  X : Cancel an appointment.                                            *" << endl;
		cout << "*  W : Save all appointments to a file.                                  *" << endl;
		cout << "*  A : Search for appointments in certain time range.                    *" << endl;
		cout << "*  E : Search for appointments in the same week.                         *" << endl;
		cout << "*  N : Search for appointments by name.                                  *" << endl;
		cout << "*  S : Sort all Appointment in order                                     *" << endl;
		cout << "*  Q : Quit the program.                                                 *" << endl;
		cout << "*                                                                        *" << endl;
		cout << "**************************************************************************" << endl;

		cout << "Choice: ";
		cin >> userChoice;
		//ask user for in put choice

		switch (userChoice)
		{

			
		case 'K': case 'k':
			//if choice is k, as user to in put informations for making an appointment and add the appointment to the end of the vector

			cin >> aAppointment;
			appointmentDB.push_back(aAppointment);
			numAppointmentRecords++;
			//update the number of elements in the vector by adding one to the numappointment, 

			break;

			
		case 'R': case 'r':

			/*If the user choice is r, ask the user for the name of the file to read the records from.
			Open the file and reading in the first number as the number of appointments in the file.
			If the number is negative, inform user that it is an invalid file.Else if, clear all the apppointment
			records in the vector and read in new records from the file.*/

			cout << endl << " Erase all birthday records and read in new records from file. " << endl;
			cout << " File name: " << endl;
			cin >> fileName;


			//open the file
			fin.open(fileName);

			// read in number of appointments in the file
			fin >> numAppointmentRecords;

			// check whether the number of appointments is negative
			if (numAppointmentRecords < 0){
				cout << "ERROR:  Invalid number of appointments." << endl;
				break;
			}
			else{
				//clear all old appointments in the vector
				appointmentDB.clear();
				cout << " All old appointments have been erased." << endl;
			}

			for (int i = 0; i < numAppointmentRecords; i++){
				// read in all appointment records in the file and add them to the end of the vector
				fin >> aAppointment;
				appointmentDB.push_back(aAppointment);
				
			}

			//close the file
			fin.close();


			cout << numAppointmentRecords << " New records added." << endl;


			break;


		case 'D': case 'd':
			//if the choice is d, display all elements in the vector

			//if the vector is empty, just break out
			if (appointmentDB.size() == 0){
				cout << "No appointment found." << endl;
				break;
			}
			//if the vector is not empty, call printinfo function to cout all informations of appointments
			else{
				for (int i = 0; i < numAppointmentRecords; i++)
					appointmentDB[i].PrintInfo();
			}

			break;


		case 'M': case 'm':
			// if the choice if m, user will be able to change the informations of an appointment

			//ask user for the index of the appointment that he wants to change
			cout << "Please enter in the index of the appointment that needs to be changed." << endl;
			cin >> index;
			index -= 1 ;
			// minuse the index by 1 becaude the first element in the vector is in index 0
			

			if (index < 0 || index > numAppointmentRecords){
				//if the index is less than 0 or higher than the number of elements in the vector, just break out

				cout << "ERROR:  Invalid index." <<endl<< endl;
				break;
			}
			else
				//if the index is valid, ask the user to enter in new informations for the appointment
				cin >> appointmentDB[index];

			break;


		case 'X': case 'x':
			// if the choice is x,  the function will delect one selected element from the vector


			// if the vector is empty, just break out,
			if (appointmentDB.size() == 0){
				cout << "No appointment found." << endl;
				break;
			}
			//else ask the user to enter in the index of the appointment that needs to be delected
			else{
				cout << "Please enter in the index of the appointment that needs to be cancelled." << endl;
				cin >> index;
				index -= 1;
				// minuse the index by 1 becaude the first element in the vector is in index 0
			}
		
		
			 if (index <0 || index >= numAppointmentRecords){
             // if the index is negative or higher than the number of elements in the vector, just break out.
				cout << "ERROR:  Invalid index." << endl;
				break;
			}
			else
				//if the index is valid, erase the element from the vector
				appointmentDB.erase(appointmentDB.begin() + (index));

			 //update the number of elements in the vector by subtracting one from the total number of elements in the vector
			    numAppointmentRecords--;

			break;


		case 'W': case 'w':

			/*If the user choice is w, ask the user for the name of the file to read the appoitment records from.
			Open the file and reading in the first number as the number of appointment records in the file.
			If the number is negative, inform user that it is an invalid file.Else if, clear all the old appointment
			records in the vector and read in new records from the file.*/

			cout << endl << " Save all appointment records to a file. " << endl;
			cout << " File name: " << endl;
			cin >> fileName;
			// ask user for the name of the file


			//open the file
			fout.open(fileName);


			fout << appointmentDB.size();
			// save the number of total elements in the vector to the file


			//save all elements in the vector to the file
			for (int i = 0; i < appointmentDB.size(); i++)
				fout << appointmentDB[i];



			//close the file
			fout.close();


			cout << appointmentDB.size() << " records saved." << endl;



			break;


		case 'A': case 'a':
			// if the choice is a, the user will set up a range of date search for any appointment that is in between

			cout << "Please enter the time range for the search." << endl;
			cout << "Beginning date, ";
			cin >> dBegin;
			//ask the user to input the beginning of the date range

			cout <<endl<< "Ending date, ";
			cin >> dEnd;
			//ask the user to input the end of the date range

			for (int i = 0; i < appointmentDB.size(); i++){
				//loop through every element in the vector, is the date of the appointment is less than the ending date and greater than
				// the beginning date, print out all information of the appointment

				if (appointmentDB[i].CompareAppointmentDay(dBegin) != -1 && appointmentDB[i].CompareAppointmentDay(dEnd) != 1)
					appointmentDB[i].PrintInfo();

			}


			break;


		case 'E': case 'e':
			// if the choice is e, ask the user to enter in a example date and search for any appointment that has that date that is within
			// the same weak with the example date

			cout << "Please enter the date for searching. " << endl;
			cin >> exampleDate;
			//ask for the example date

			referenceD.SetDate(5, 3, 2015);
			//This is reference of the first day of the week, which is sunday

			

			if (exampleDate > referenceD){

				/* if the example date is greater than the reference date, take the difference of these two dates and % it by 7 because
				 there are 7 days in a weak. The remainder will tell what day of a week is the example date. If the remainder is 3, 
				 it is a wendsday. if the remainder is 5, it is a friday. Therefore, if we take the example date and subtract the remainder, 
				 it will alway be a sunday. We than set up the beginning date of a date range to the date of example date subtract the 
				 remainder, which will be a sunday. We also set up the endding date of the date range to the date of example date
				 plus  7 - the remainder. This way, the ending date will always be a saturday, which is the end of a week. At last, we
				 loop through the vector and print out the information of appointments that has the date within the date range*/


				dBegin = exampleDate - ((exampleDate - referenceD) % 7);
				dEnd = exampleDate + (7 - ((exampleDate - referenceD) % 7));
			}
			else if (exampleDate < referenceD){
				dBegin = exampleDate - ((referenceD - exampleDate) % 7);
				dEnd = exampleDate + (7 - ((referenceD - exampleDate) % 7));
			}
			else if (exampleDate == referenceD){
				dBegin = exampleDate;
				dEnd = exampleDate + 7;
			}


			for (int i = 0, c =0; i < appointmentDB.size(); i++){

				if (appointmentDB[i].CompareAppointmentDay(dBegin) != -1 && appointmentDB[i].CompareAppointmentDay(dEnd) != 1){
					cout << "Appointment found: ";
					appointmentDB[i].PrintInfo();
					c++;
				}

				if (i == appointmentDB.size()-1 && c == 0)
					cout << "Not appointment found." << endl;

			}


			



			break;


		case 'N': case 'n':
			//if the choice is n, ask user for the first name and last name. Loop through every elements in the vector and print out
			// all information of appointments that has the matched first and last name.

			cout << "Please enter the first name: ";
			cin >> aFirstName;
			cout << "Please enter the last name: ";
			cin >> aLastName;

			for (int i = 0; i < appointmentDB.size(); i++){

				if (appointmentDB[i].SameFullName(aFirstName, aLastName) == true)
					appointmentDB[i].PrintInfo();
			}



			break;


		case 'S': case 's':
			// if the choice is s, call the mergesort function to sort all appointment.

			mergeSort(appointmentDB);

			cout << "All appointments have been sorted." << endl;


			break;

		case 'Q': case 'q':
			// if the choice is q, quit the program

		
			cout << "Thank you for using the program. " << endl;
			inMenu = false;
			break;




		default:
			cout << "Invalid choice" << endl;
		
		}

	}

	char c;
	cin >> c;
}




