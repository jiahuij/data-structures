// File: main.cpp

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

void main()
{
  List myList;

  char c;

  cout<< endl << endl
	  << "********************************************" << endl
	  << "Demonstration of an \"unsorted\" linked list" << endl
	  << "********************************************" << endl;

  cout << endl << "Insert 3 by calling myList.Insert(3)"  << endl;
  myList.Insert(3);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();
  cout << endl << "Insert 4 by calling myList.Insert(4)"  << endl;
  myList.Insert(4);
  cout << endl << "Display the contents of list" << endl;
  myList.Display();

  cout << endl << "Enter c to continue" << endl << endl; 
  cin >>c;

  cout << endl << "Insert 9 by calling myList.Insert(9)"  << endl;
  myList.Insert(9);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();
  cout << endl << "Insert 2 by calling myList.Insert(2)"  << endl;
  myList.Insert(2);
  cout << endl << "Display the contents of list" << endl;
  myList.Display();

  cout << endl << "Enter c to continue" << endl << endl; 
  cin >>c;

  cout << endl << "Remove 4 by calling myList.Remove(4)"  << endl;
  myList.Remove(4);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();
  cout << endl << "Remove 2 by calling myList.Remove(2)"  << endl;
  myList.Remove(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();

  cout << endl << "Enter c to continue" << endl << endl; 
  cin >>c;
  
  cout << endl << "Clear the whole list"  << endl;
  myList.Clear();
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();

  cout << endl << "Enter c to continue" << endl << endl; 
  cin >>c;
  


  cout<< endl << endl
	  << "********************************************" << endl
	  << "Demonstration of a \"sorted\" linked list" << endl
	  << "********************************************" << endl;

  cout << endl << "Insert 3 by calling myList.InsertInOrder(3)"  << endl;
  myList.InsertInOrder(3);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();
  cout << endl << "Insert 4 by calling myList.InsertInOrder(4)"  << endl;
  myList.InsertInOrder(4);
  cout << endl << "Display the contents of list" << endl;
  myList.Display();

  cout << endl << "Enter c to continue" << endl << endl; 
  cin >>c;

  cout << endl << "Insert 9 by calling myList.InsertInOrder(9)"  << endl;
  myList.InsertInOrder(9);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();
  cout << endl << "Insert 2 by calling myList.InsertInOrder(2)"  << endl;
  myList.InsertInOrder(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();

  cout << endl << "Insert 2 again by calling myList.InsertInOrder(2)"  << endl;
  myList.InsertInOrder(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();

  cout << endl << "Enter c to continue" << endl << endl; 
  cin >>c;

  cout << endl << "Remove 4 by calling myList.Remove(4)"  << endl;
  myList.Remove(4);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();
  cout << endl << "Remove 2 by calling myList.Remove(2)"  << endl;
  myList.Remove(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();

  cout << endl << "Try to remove 2 again by calling myList.Remove(2)"  << endl;
  myList.Remove(2);
  cout << endl << "Display the contents of list" << endl ;
  myList.Display();

  cout << endl << "Enter c to continue" << endl << endl; 
  cin >>c;

  myList.Clear();
  cout<< endl << endl
	  << "********************************************" << endl
	  << " myList.Clear();  " << endl
	  << "********************************************" << endl;



  cout<< endl << endl
	  << "********************************************" << endl
	  << "Demonstration of writing the contents of a linked list into a file" << endl
	  << "********************************************" << endl;


  cin >> myList;
  myList.Display();

  
  cout<< endl << endl
	  << "********************************************" << endl
	  << " Writing the contents into the file test.txt" << endl
	  << " fout.open(\"test.txt\");  fout << myList; " << endl
	  << " Check the contents of \"test.txt\" now to see whether it works." << endl
	  << "********************************************" << endl;

  ofstream fout;
  fout.open("test.txt");
  fout << myList;
  fout.close();
  
  cout << endl << "Enter c to continue" << endl << endl; 
  cin >>c;
  
   cout<< endl 
	  << "********************************************" << endl
	  << " Demonstration of myList.FindAndDisplay(v1, v2); " << endl
	  << "********************************************" << endl;

   int v1, v2;
   cout << "Enter an integer, v1="; cin >> v1;
   cout << "Enter an integer, v2="; cin >> v2;
   myList.FindAndDisplay(v1, v2);



  cout<< endl << endl
	  << "*************************************************************" << endl
	  << "This is the end of demonstration. Enter a character to quit" << endl;

  char x; cin >>x;


}




