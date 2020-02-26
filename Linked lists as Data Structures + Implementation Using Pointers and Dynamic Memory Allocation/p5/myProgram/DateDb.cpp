#include "DateType.h"
#include <vector>
#include <algorithm>  
#include <string>
#include <fstream>
#include <iostream>



using namespace std;


//This function merges two vectors into one vector.
bool mergeTwoSortedVectors(vector<DateType> & vecA, vector< DateType > & vecB, vector< DateType > & vecC){

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
 bool mergeSort(vector<DateType> & vecToSort){
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


		vector<DateType>  vec1, vec2;
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


int main(){


	int numDateRecords = 0, vectorIndex;
	// numDateRecords: checking the number of elements in the vector. 
    //vectprIndex: store the number from user for the index of the vector

	bool inMenu = true;//inMenue: flage for the manu
	char userChoice;// userChoice: store user input for the choice


	DateType date, dBegin, dEnd;// All for storing temperary date records

	string filename;// store the file name user will enter 

	ifstream fin;// input text from the file
	ofstream fout;// output text from the file


	vector<DateType> dateDB;// DataType vector that stores birthday records

	while (inMenu){

		//Display menu
		cout << "**********************************  Menu **********************************" << endl;
		cout << "*                                                                         *" << endl;
		cout << "*    K.  Add new birthday                                                 *" << endl;
		cout << "*    D.  Display all birthday records                                     *" << endl;
		cout << "*    M.  Change a birthday record                                         *" << endl;
		cout << "*    W.  Save all birthday records to a file                              *" << endl;
		cout << "*    F.  Find birthday                                                    *" << endl;
		cout << "*    B.  Erase all birthdat records and reading new records from file     *" << endl;
		cout << "*    S.  Sort the birthday records                                        *" << endl;
		cout << "*    Q.  Quit the program                                                 *" << endl;
		cout << "*                                                                         *" << endl;
		cout << "***************************************************************************" << endl;

		cout << endl << "Choice: ";
		cin >> userChoice;

		switch (userChoice){

		case 'k': case 'K':
			//If the userChoice is K,call readDate function to read in the date from the user and store it to the DB vector

			cout << endl << "New birthday record." << endl;
			date.ReadDate();

			dateDB.push_back(date);

			cout << endl << "New record added." << endl;
			numDateRecords++;
			break;


		case 'd': case 'D':
			// if the user choice is d, display all the elements in the vector in the scream

			for (int i = 0; i < numDateRecords; i++)

				cout << "Record " << i+1 << ": " << dateDB[i].YearIs() << "/" << dateDB[i].MonthIs() << "/" << dateDB[i].DayIs() << endl;

			break;

		case 'm': case 'M':
			// if the user choice is m, ask the user for the index of the record that needs to be changed and
			// ask the user to input the new record

			cout << "Enter the index of the birthday record to be changed." << endl;
			cin >> vectorIndex;

			// if the index in negative for higher than the number of elements in the vector, inform error
			if (vectorIndex < 0 || vectorIndex > dateDB.size())
				cout << "Invalid index!" << endl;

			//ask the user to input the new record
			else{
				cin >> dateDB[vectorIndex-1];

				cout << "Change made." << endl;
			}
			break;

		case 'w': case 'W':
		//if the user choice is w, ask for the name of the file to save the records. Open the file and save all records in.

			cout <<endl<< "Saving all records to file" << endl;
			cout << "File name: " << endl;
			cin >> filename;

			//open the file
			fout.open(filename);
		
			//save the  numnber of records in the vector to the file first
			fout << dateDB.size() << endl;

			// save all records to the file
			for (int i = 0; i < dateDB.size(); i++)
				fout << dateDB[i] << endl;

			//close file
			fout.close();

			cout << "Records saved." << endl;
			break;


		case 'f': case 'F':
			// if the user choice is f, ask user to enter the range of the date user wants to search

			cout << "Searching birthday records." << endl;
			cout << "Please enter the range of the date for the search." << endl;

			//ask the user to enter the beginning of the range of the date
			cout << "Beginning date: " << endl;
			cin >> dBegin;

			//ask the user to enter the ending of the range of the date
			cout << "Ending date: " << endl;
			cin >> dEnd;

			//loop through all elements in the vector, if the date is greater than the beginning date and smaller than 
			// the ending date, diaplay the date.
			for (int e=0,i = 0; i < dateDB.size(); i++){

				if (dBegin <= dateDB[i] && dateDB[i] <= dEnd == true){
					cout << endl << "Record " << i + 1 << ":  " << dateDB[i] << endl;
					e++;
				}
				// if no record was found, inform the user.
				if (i>0 && e == 0)
					cout << "No records found." << endl;
				
			}
	
			break;

		case 'S': case 's':
			// if the user choice is s, call the mergesort function to sort the vector.
			mergeSort(dateDB);
			cout << "Birthday records have been sorted." << endl;
			break;


		case 'b': case 'B':
			/*If the user choice is b, ask the user for the name of the file to read the records from.
			Open the file and reading in the first number as the number of birthhday records in the file.
			If the number is negative, inform user that it is an invalid file.Else if, clear all the birthday
			records in the vector and read in new records from the file.*/

			cout << endl << " Erase all birthday records ans reading in new records from file. " << endl;
			cout << " File name: " << endl;
			cin >> filename;

			//open the file
			fin.open(filename);

			// read in the first number as the number of records in the file
			fin >> numDateRecords;

			// if the number is negative, inform it is invalid
			if (numDateRecords <= 0)
				cout << "Invalid file" << endl;

			//if the number is positive, clear the vector and read in the records from the file and save them in the vector
			else{

				dateDB.clear();
				cout << "All records have been erased." << endl;

				for (int i = 0; i < numDateRecords; i++){

					fin >> (date);

					dateDB.push_back(date);
				}

				//close the file
				fin.close();

				cout << "New records added." << endl;

			}
			break;

		case 'Q': case 'q':

			cout << "Thank you for using the program   :) " << endl;
			inMenu = false;
			break;

		default:
			cout << "Invalid choice" << endl;
		}
	}

         char c;
		cin >> c;
		return 0;
	}
	