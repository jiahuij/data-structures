#include "Tree.h"
#include <cmath>

void main()
{
	

	
	Tree myTree;// create an empty tree 
	DateType myDate; // to store temperary dates which will be insert into the tree
	char input;// to store user menu choice
	int heightArray[1000];// creat an array to store 1000 tree heights
	int averageHeight = 0;// to store the average height of 1000 tree
	int totalHeight = 0;// to store the total height of 1000 tree. For culculating the average
	int n = 0;
	double  sumOfSquaredErrors = 0;// to store the sum of all difference between the average tree height and every tree height
	double deviation = 0;// to store the deviation of sumOfSquaredErrors
	double withInOne = 0;// to keep on checking the number of tree height in a range
	double withInTwo = 0;// to keep on checking the number of tree height in a range
	double percentageOne = 0;// to hold the perventage of number of tree heights in rang over totall number of tree heightthe 
	double percentageTwo = 0;// to hold the perventage of number of tree heights in rang over totall number of tree heightthe 
	
	

	bool flag = true;
	// for display menu

	while (flag){

		
		cout << endl << endl << endl;
		cout << "************************* Menu ************************" << endl;
		cout<< "*      T:  Insert a date.                             *" << endl;
		cout << "*      H:  Display the height of tyhe tree.           *" << endl;
		cout << "*      K:  Clear the tree.                            *" << endl;
		cout << "*      Z:  Average hight.                             *" << endl;
		cout << "*******************************************************" << endl;
		cin >> input;


		switch (input)
		{

			// of the user choice is c,
		case'T':; case 't':
			cout << "Please enter in a date:"<<endl;
			cin >> myDate;
				//ask the user to input a date and store it in myDate

			myTree.Insert (myDate);
			cout << "Date saved." << endl;
			//insert the date to the tree by calling the insert function
			break;
			
		case'H':; case 'h':
			//if the user choice is h, call the Height function to get the height of the tree
			cout << "Tree height: " << myTree.Height() << endl;

			break;


		case'K':; case 'k':
			// if the user choice is k, call the clear function to delete all nodes in the tree
			myTree.Clear();
			cout << "Tree has been cleared." << endl;
			break;
		
		case'Z':; case 'z':
			//if the user choice is z,
			

			cout << "PLease enter the numner of random date to be insert in each random tree." << endl;
			cin >> n;
			//ask user to input the numbr of tree node to be randomly generated in each tree

			for (int i = 0; i < 1000; i++){
				//loop throug all 1000 elements of the array created.In each loop, clear the tree and randomly insert the number
				// of nodes that user wants to insert and call the height function to get the height of newly created tree and
				//save it in the array created. Add the height to the totalHeight.


				myTree.Clear();
				
				for (int j = 0; j < n; j++){
					myDate.SetRandomDate();
					myTree.Insert(myDate);
			
				}
				
			
				heightArray[i] = myTree.Height();
			
				totalHeight += heightArray[i];
				cout << i << endl;
			}
		
			// divide the totalHeight by 1000 to get the average of tree height
			averageHeight = totalHeight / 1000;
			cout << "Average Height: " << averageHeight << endl;
		
			// loop through every height in the array and get the sum of all differences of every height and the average height
			for (int i = 0; i < 999; i++)	
				sumOfSquaredErrors += pow ((heightArray[i] - averageHeight),2);

			
			// divide the sum by 1000 to get the deviation 
			deviation = sqrt(sumOfSquaredErrors / 1000);
		
			//loop through all heights in the array, if the height is in range, add one to the record
			for (int i = 0; i < 1000; i++){
				if (heightArray[i]>(averageHeight - 2*deviation) && heightArray[i] < (averageHeight + 2*deviation))
					withInOne++;
			}
			//loop through all heights in the array, if the height is in range, add one to the record
			for (int i = 0; i < 1000; i++){
				if (heightArray[i]>(averageHeight - 3 * deviation) && heightArray[i] < (averageHeight + 3 * deviation))
					withInTwo++;
			}
			// divide the number of heights found in the rande by 1000  and * 100 to get the percentage of it.
			percentageOne = (withInOne/1000)*100 ;
			percentageTwo = (withInTwo / 1000) * 100;
			
			//display th persentages
			cout << "Percentage with in 2: " << percentageOne << endl;
			cout << "Percentage with in 3: " << percentageTwo << endl;

			//reset all  data 
			 totalHeight = 0;
			 sumOfSquaredErrors = 0;
		     withInOne = 0;
			 withInTwo = 0;
			break;



		default:
			cout << "Invalid choice" << endl;
			break;
		}
	

	}

		

   char X;
   cin >> X;


}
