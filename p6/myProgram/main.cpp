// File: main.cpp

#include <iostream>
#include <string>
#include "LinkedList.h"
#include <fstream>

using namespace std;

void main()
{
	List dateDB;

	string filename;

	DateType d, date, dBegin, dEnd;

	ifstream fin;
	ofstream fout;

	int numDateRecords =0;
	int n;

	
	char userChoice;

	bool inMenu = true;


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
		cout << "*    X.  Clear all records and insert random records in order             *" << endl;
		cout << "*    Y.  Clear all records and insert random records                      *" << endl;
		cout << "*    Z.  Randomly romove records                                          *" << endl;
		cout << "*    Q.  Quit the program                                                 *" << endl;
		cout << "*                                                                         *" << endl;
		cout << "***************************************************************************" << endl;

		cout << endl << "Choice: ";
		cin >> userChoice;

		switch (userChoice){

		case 'k': case 'K':
			//If the userChoice is K,call readDate function to read in the date from the user and store it to the DB vector

			cout << endl << "New birthday record." << endl;
			cin >> date;

			dateDB.InsertInOrder(date);

			cout << endl << "New record added." << endl;
			numDateRecords++;
			break;


		case 'd': case 'D':
			// if the user choice is d, display all the elements in the vector in the scream

				dateDB.Display();
				
			break;

		case 'm': case 'M':
			// if the user choice is m, ask the user for the index of the record that needs to be changed and
			// ask the user to input the new record

			cout << "Enter the date to be changed." << endl;
			cin >> date;


			dateDB.Remove(date);

		
			cout << "Enter the new date." << endl;
			cin >> date;


			dateDB.InsertInOrder(date);

			break;

		case 'w': case 'W':
			//if the user choice is w, ask for the name of the file to save the records. Open the file and save all records in.

			cout << endl << "Saving all records to file" << endl;
			cout << "File name: " << endl;
			cin >> filename;

			//open the file
			fout.open(filename);

			
			// save all records to the file
			for (int i = 0; i <numDateRecords; i++)
				fout << dateDB;

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

			//call the FindAndDisplay function
			dateDB.FindAndDisplay(dBegin, dEnd);

			break;

		

		case 'b': case 'B':
			/*If the user choice is b, ask the user for the name of the file to read the records from.
			Open the file and reading in the first number as the number of birthhday records in the file.
			If the number is negative, inform user that it is an invalid file.Else if, clear all the birthday
			records in the vector and read in new records from the file.*/

			cout << endl << " Erase all birthday records and read in new records from file. " << endl;
			cout << " File name: " << endl;
			cin >> filename;
			

			//open the file
			fin.open(filename);

		
			for (int i = 0; i <numDateRecords; i++)
				fin >> dateDB;
			
				//close the file
				fin.close();

			
				cout << numDateRecords<< " New records added." << endl;

			
			break;

		case 'Q': case 'q':

			cout << "Thank you for using the program   :) " << endl;
			inMenu = false;
			break;

		case 'X': case 'x':
			//clear all the birthday records and ask user to enter in the number of new random records to insert in oeder.
			
			dateDB.Clear();
			cout << endl << "All records has been removed." << endl;
			cout << "Please enter in the number of random records to insert." << endl;
			cin >> n;

			for (int i = 0; i < n; i++){

				d.SetRandomDate();
				//call SeTRandomDate to get a random date and call insertInOder to insert the date in to the list.
				
				dateDB.InsertInOrder(d);
			}
		
			break;

		case 'Y': case 'y':
			//clear all the birthday records and ask user to enter in the number of new random records to insert with no order.

			dateDB.Clear();
			cout << endl << "All records has been removed." << endl;
			cout << "Please enter in the number of random records to insert." << endl;
			cin >> n;

			for (int i = 0; i < n; i++){

				d.SetRandomDate();
				//call SeTRandomDate to get a random date and call insert to insert the date in to the list.

				dateDB.Insert(d);
			}
			break;

		case 'Z': case 'z':
			//ask user to enter in the number of random records to be removed.
		
			cout << "Please enter in the number of random records to be removed." << endl;
			cin >> n;

			for (int i = 0; i < n; i++){

				d.SetRandomDate();
				//call SeTRandomDate to get a random date and call Remove to remove the date from the list if it matches.
				

				dateDB.Remove(d);
			}
			break;

		default:
			cout << "Invalid choice" << endl;
		}
	}

	char c;
	cin >> c;

}





