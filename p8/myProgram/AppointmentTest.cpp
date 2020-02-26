// File: appointmentTest.cpp

#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "Appointment.h"

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
		cout << "Error:  Vectors are not sorted." << endl;
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


void main()
{
 //Declare a vector initialized to have 5 elements
 vector<Appointment> appointmentDB(INITIAL_DB_SIZE);
 vector<Appointment> appointmentTest(INITIAL_DB_SIZE);
 vector<Appointment> appointmentResult(6);



 //Test Stage A.1
 cout << "***********  Stage A.1: test ReadInfo ************" << endl;
 cout << "Build up a database of " <<  INITIAL_DB_SIZE << " records of appointment information."
	  << endl << endl;
 for (int i=0; i<appointmentDB.size(); i++)
	appointmentDB[i].ReadInfo();




 //Test Stage B.1
 cout << "***********  Stage B.1:  test >> operation************" << endl;
 cout << "Build up a database of " <<  INITIAL_DB_SIZE << " records of appointment information."
	  << endl << endl;
 for (int i=0; i<appointmentDB.size(); i++)
	cin>>appointmentDB[i];




 //Test Stage B.2
 cout << endl << endl
	 << "***********  Stage B.2: test << operation ************" << endl;
 cout << "Print out the contents of the database of "
	  << endl << endl;
 for (int i=0; i<appointmentDB.size(); i++)
	cout << appointmentDB[i];



 //Test Stage 3
 cout << endl << endl
	  << "***********  Stage 3 ************" << endl;
 cout << "Search the appointment information of people of a particular name "
	  << endl << endl;
 string someFirstName, someLastName;

 cout << "What is the first name:";
 cin  >> someFirstName;
 cout << endl << "What is the last name:";
 cin  >> someLastName;
 cout << endl << endl;

 for (int i=0; i<appointmentDB.size(); i++)
	if ( appointmentDB[i].SameFullName(someFirstName, someLastName) )
		appointmentDB[i].PrintInfo();


 //Test Stage 4
 cout << endl << endl
	  << "***********  Stage 4 ************" << endl;
 cout << "Search the appointment information of people born in a particular date "
	  << endl << endl;
 DateType someDate;
 cout << "What is the date:" << endl;
 someDate.ReadDate();

 for (int i=0; i<appointmentDB.size(); i++)
	if ( appointmentDB[i].SameAppointmentDay(someDate) )
		appointmentDB[i].PrintInfo();

 

 char c;
 cin >> c;
}




