#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;


//This function merges two vectors together into one vector in an ascending order.
bool mergeTwoSortedVectors(vector<double> & vecA, vector<double> & vecB, vector<double> & vecC){

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

				else if (vecA[countA]  >= vecB[countB]){
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
void mergeSort(vector<double> & vecToSort)
{
	int counter = 0;

	// If the vector passed in has only one number, just return 
	if (vecToSort.size() == 1){
	
		return;
	}
	else if (vecToSort.size() == 2){
		//If the vector passed in has only two numbers, check if the first number is larger than the second number.
		// if the first number is larger, swap the numbers and return.
	
		if (vecToSort[0] > vecToSort[1])
			std::swap(vecToSort[0], vecToSort[1]);

		return;
		
	}

	else if (vecToSort.size() > 2){
		// if the passed in vector has more than three numbers in it, divid the vectors passed in into two vector and keep on dividing until
		// there is only two numbers in the vector and call the function itself to check if the first number is larger or smaller.
	

		vector<double>  vec1, vec2;
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


int main()
{
	// for storing tht size of the vectors
	int sizaA;
	int sizeB;
	int sizeD =0;


	vector<double> VecA;
	vector<double> VecB;
	vector<double> VecC;
	vector<double> VecD;

	//Aske the user to pass in the size of the vecA and save it to sizeA
	cout << "Please enter the size of two vectors" << endl;

	cout << "Vector 1: ";
	cin >> sizaA;
	VecA.resize(sizaA);

	//Aske the user to pass in the size of the vecB and save it to sizeB
	cout << "Vector 2: ";
	cin >> sizeB;
	VecB.resize(sizeB);


	//Ask the user to enter in the value in the first vector
	cout << "Please enter the value in the first vector " << endl;

	for (int i = 0; i < VecA.size(); i++){
		cout << "Element # "<< i+1 <<": ";
		cin >> VecA[i];			
	}
	
	//Ask the user to enter in the value in the first vector
	cout << "Please enter the value in the first vector " << endl;

	for (int i = 0; i < VecB.size(); i++){
		cout << "Element # " << i+1 << ": ";
		cin >> VecB[i];
	}


	//call the function that merges two vectors into vecC and display it to the scream
	if (mergeTwoSortedVectors(VecA, VecB, VecC)){

		cout << endl << "*** Merged vector contains ***" << endl;

		mergeTwoSortedVectors(VecA, VecB, VecC);

		for (int i = 0; i < VecC.size(); i++)
			cout << "Element #" << i << ": " << VecC[i] << endl;
	}

	//If the mergeTwoSortedVectors function returns false, which means the vecA or vecB is not in proper order, notify the user for the  error
	else
		cout << endl << "ERROR: The number in the first or the second vector is not in ascending order." << endl;



	// This loops also long as user enter in a positive number for the size of vecD
	while (sizeD >= 0){


		//ask the user to enter in the size of vecD
		cout<<endl << "*** Serious sorting ***" << endl;

		cout << "Please enter size of the vector to be sorted." << endl;
		cout << "Enter negative number to end the function." << endl << endl;

		cout << "Vector size: ";
		cin >> sizeD;


		if (sizeD >= 0){

			// set the size of vecD to the size user entered.
			VecD.resize(sizeD);


			//ask the user to enter in the values for the vector
			cout << "Please enter the value in the vector." << endl;

			for (int i = 0; i < VecD.size(); i++){
				cout << "Element #" << i << ": ";
				cin >> VecD[i];
			}

			// call the function that sorted the values in the vecD
			mergeSort(VecD);


			cout << endl << "*** Sorted  ***" << endl;

			// display the sorted values to the screem
			for (int i = 0; i < VecD.size(); i++){
				cout << "Element #" << i << ": " << VecD[i] << endl;;

			}
		}
		else{
			cout << endl << "Thank you for using the program." << endl;
			char c;
			cin >> c;
			return 0;
		}
	}

	char c;
	cin >> c;
	return 0;

}