#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;
//This function merges two series of values into one serie of values and return true. If the series of values
//passed in are not sorted or the siezs of the series of values passed in are 0, it will return false
bool mergeTwoSortedSeries(double * ptrA, int sizeOfA, double * ptrB, int sizeOfB, double * ptrC)
{
	/* sizeOfC: to hold the size of array C
	   counter A,B,C : use to keep count the numer of elements that had been merged 
	   sorted A,B: to keep check if the passed in arrays are sorted.*/


	int sizeOfC;
	int countA = 0;
	int countB = 0;
	int countC = 0;
	bool sortedA = true;
	bool sortedB = true;

	//set the size of arrayC to the sum of the sizes of arrayA and arrayB
	sizeOfC = sizeOfA + sizeOfB;

	// if the sizes of passed in array = 0, return false
	if (sizeOfA < 0|| sizeOfB <0)
		return false;


	//Check if the the passed in arrayA is in ascending order. 
	for (int i = 0; i < sizeOfA - 1; i++){

		if (ptrA[i] > ptrA[i + 1]){
			sortedA = false;
			break;
		}

	}

	//Check if the the arrayB is in ascending order.
	for (int i = 0; i <sizeOfB - 1; i++){

		if (ptrB[i]> ptrB[i + 1]){
			sortedB = false;
			break;
		}

	}

	// If either of the passed in array is not in ascending order, just return false.
	if (sortedA == false || sortedB == false)
          return false;
	

	else{

		while (countC != sizeOfC){
	   //Keep on looping until all elements in both passed in series of values are transfered to arrayC.



			if (countA != sizeOfA && countB != sizeOfB){
		// Keep on checking if series of values are going out of range

				if (ptrA[countA] < ptrB[countB]){
		// if the number in ptrA is smaller, save the number into ptrC and undate the counters for both ptrA and PtrC.

					ptrC[countC] = ptrA[countA];
					countA++;
					countC++;
				}

				else if (ptrA[countA] >= ptrB[countB]){
		 // if the number in ptrB is smaller, save the number into ptrC and undate the counters for both ptrB and ptrC.

					ptrC[countC] = ptrB[countB];
					countB++;
					countC++;

				}
			}

 // If All the number in ptrA had been saved in ptrC, save the remaining number in ptrB into ptrC
			if (countA == sizeOfA){

				ptrC[countC] = ptrB[countB];
				countB++;
				countC++;

			}

			// If All the number in ptrB had been saved in ptrC, save the remaining number in ptrA into ptrC
			else if (countB == sizeOfB){

				ptrC[countC] = ptrA[countA];
				countA++;
				countC++;


			}


		}

		return true;
	}
	

}

//This function will sort the passed in series of values in ascending order.

void mergeSort(double * ptrSeriesToSort, int sizeOfSeries){

	/* size1,2 : for the size of two arrays.
	   counter : to keep on counting the elements that had been saved to ptrSeriesToSort.
	*/
	int size1, size2;
	int counter = 0;

	// if the size of passed in array has 0 element, just return 
	if (sizeOfSeries < 0 || ptrSeriesToSort == 0)
		return ;

	else{
		
		// If the array passed in has only one element, just return 
		if (sizeOfSeries == 1){

			return;
		}

		else if (sizeOfSeries == 2){
			//If the array passed in has only two element, check if the first number is larger than the second number.
			// if the first number is larger, swap the numbers and return.

			if (ptrSeriesToSort[0] > ptrSeriesToSort[1])
				std::swap(ptrSeriesToSort[0], ptrSeriesToSort[1]);

			return;

		}

		else if (sizeOfSeries > 2){
			// if the passed in array has more than three numbers in it,
			// divid the array passed in into two arrays and keep on dividing until
			// there is only two numbers in the vector and
			// call the function itself to check if the first number is larger or smaller.


		   // create two pointers  
			double *ptr1 = nullptr, *ptr2 = nullptr;
			
			// set the size of ptr1 to the half of the size of passed in array
			size1 = sizeOfSeries / 2;
			// set the size of ptr2 to the half of the half of the size of passed in array
			size2 = (sizeOfSeries - (sizeOfSeries / 2));

			//Dynamically allocate two chucks of memory to hold the element in passed in array
			ptr1 = new double[size1];
			ptr2 = new double[size2];


			

			// save the elements in the first array into the passed in array
			for (int i = 0; i < size1; i++){
				ptr1[i] = ptrSeriesToSort[counter];
				counter++;
			}

			// save the  the second array  to the passed in array
			for (int i = 0; i < size2; i++){
				ptr2[i] = ptrSeriesToSort[counter];
				counter++;
			}

			// call the mergeTwoSortedSeries functiont to check if both ptr1 and ptr2 is in order. 
			//if they are not in order, call the function itself to divid the vector again
			if (!mergeTwoSortedSeries(ptr1, size1, ptr2, size2,ptrSeriesToSort)){

				mergeSort(ptr1,size1);
				mergeSort(ptr2,size2);
				mergeTwoSortedSeries(ptr1, size1, ptr2, size2, ptrSeriesToSort);
			}
			// releaze the memory
			delete[] ptr1;
			delete[] ptr2;
		}


	}
}

int main()
{
	/*  *ptrA,B,C,D : pointers for dynamically allocate  chucks of memory
	     sizeOfA,B,C,D : for the size of arrays.
		 flag : to check if the passed in values of arrays are in ascending order.
	*/
	double *ptrA = nullptr, *ptrB = nullptr, *ptrC = nullptr, *ptrD =nullptr;
	int sizeOfA = 0, sizeOfB = 0, sizeOfC = 0, sizeOfD = 0;
	bool flag = true;

	// check if the size of arrays entered are not negative numbers
	while (!(sizeOfA > 0 && sizeOfA > 0)){

    // ask the user to enter in the sizes of arrays
	cout << "Please enter the sizes of arrays." << endl;
	cout << "Size 1: ";
	cin >> sizeOfA;
	cout << endl << "Size 2: ";
	cin >> sizeOfB;

	// If the sizes entered in are smaller than 0, display error message
	if (sizeOfA <= 0 || sizeOfA <= 0)
		cout << endl << "Sizes of arrays shouldn't be smaller than 1." << endl<<endl;

	
	else{
		//set the size of ptrC to the sum of the sizes of ptrA and ptrB
		sizeOfC = sizeOfA + sizeOfB;

		//dynamically allocate  chucks of memory for ptrA,B,C
		ptrA = new double[sizeOfA];
		ptrB = new double[sizeOfB];
		ptrC = new double[sizeOfC];
	}
}

	while (flag){

		//ask the user to input the values of ptrA and ptrB
		cout << endl << "Please enter the values for first array. " << endl;

		for (int i = 0; i < sizeOfA; i++){
			cout << "value " << i + 1 << ": ";
			cin >> ptrA[i];
		}


		cout << endl << "Please enter the values for second array. " << endl;

		for (int i = 0; i < sizeOfB; i++){
			cout << "value " << i + 1 << ": ";
			cin >> ptrB[i];
		}

		
		if (mergeTwoSortedSeries(ptrA, sizeOfA, ptrB, sizeOfB, ptrC)){
			//call the mergeTwoSortedSeries function to check if the values passed are in ascending order
	

			//if the values are in order, call the mergeTwoSortedSeries function 
			//that will merge ptrA and ptrB and save them into ptrC 

			mergeTwoSortedSeries(ptrA, sizeOfA, ptrB, sizeOfB, ptrC);

			cout << "*********** After merge *************" << endl;

			// display the values int ptrC 
			for (int i = 0; i < sizeOfC; i++)
				cout << "value " << i + 1 << ": " << ptrC[i] << endl;

			//set the flag to false;
			flag = false;
		}

		else
			// if the value are not in order, display the error message
			cout <<endl<< "The values passed in must be in ascending order." << endl<<endl;

		
	}

	// release the memories
	delete[] ptrA;
	delete[] ptrB;
	
	// check if the size of ptrD that will be passed in is  not a negative number 
	while (!(sizeOfD > 0)){

		cout <<endl<< "Please enter the size for an array." << endl;
		cout << "Size: ";
		cin >> sizeOfD;
		
		// if the size passed in is negative, display the error message
		if (sizeOfD <= 0 )
			cout << endl << "Sizes of arrays shouldn't be smaller than 1." << endl << endl;

		else
			//dynamically allocate  chuck of memory for ptrD
			ptrD = new double[sizeOfD];

		cout << endl << "Please enter the values for the array. " << endl;

		//ask the user to enter the values for ptrD
		for (int i = 0; i < sizeOfD; i++){
			cout << "value " << i + 1 << ": ";
			cin >> ptrD[i];
		}

		// call the mergeSort function which will sort the values passed in in ptrD
		mergeSort(ptrD, sizeOfD);

		cout << "*********** After sorted *************" << endl;

		//display ptrD 
		for (int i = 0; i < sizeOfD; i++)
			cout << "value " << i + 1 << ": " << ptrD[i] << endl;
		

		//release memories
		delete[] ptrD;
		
	}

	cout << endl << "END";

	char c;
	cin >> c;
	return 0;
}
