#ifndef MY_BINARY_SEARCH_TREE_H
#define MY_BINARY_SEARCH_TREE_H
#include "DateType.h"

#include <iostream>
using namespace std;

struct TreeNode
{
   DateType Value;
   TreeNode * Left;
   TreeNode * Right;
 };



class Tree
{
   public:
     Tree();
     ~Tree();

	 //Return the height of th e tree
	 int Height();

     void Display();
	 //Display the contents of the tree

     void Write(ostream & output);
	 //Write the contents of the tree into an output (the console or a file) 

	 void Insert(DateType Val);
 	 //Store a new value into the tree 

	 bool Search(DateType Val);
	 //Search to see whether a given value is in the tree 

	 void Delete(DateType Val);
	 //Delete a value from the tree if it is stored in a node
	 
	 void Clear();					
	 //Clear up the tree to make it an empty tree.
	 //Delete all the nodes from tree.


   private:
     TreeNode * Root;

	 //Return the height from the root passed in to the deepest leaf
	 int BranchHeight(TreeNode *ptrNode);

     void DisplayTree(TreeNode * SubtreeRoot);
	 //This is the backbone implementing the core of the public Display method.
	 //	It displays the subtree.

     void WriteTree(ostream & output, TreeNode * SubtreeRoot);
	 //This is the backbone implementing the core of the public Write method.
	 //	It writes out the contents of the subtree.
	 
	 void InsertTree(TreeNode * & SubtreeRoot, DateType Val);
	 //This is the backbone implementing the core of the public Insert method.
	 // It inserts into the subtree.

	 bool SearchTree(TreeNode * SubtreeRoot, DateType Val);
	 //This is the backbone implementing the core of the public Search method.
	 // It searches into the subtree.

     void DeleteCompleteTree(TreeNode * SubtreeRoot);
	 //This is the backbone implementing the core of the destructor ~Tree().
	 // It deletes an entire subtree.


	 void DeleteItem(TreeNode * & SubtreeRoot, DateType item);
	//This is the backbone implementing the core of the public Delete method.
	// Deletes the item from the subtree.

	void DeleteNode(TreeNode * & SubtreeRoot);
	//This supports the implementation of the DeleteItem method above.
	// Deletes the node pointed to by SubtreeRoot.

	bool GetPredecessor(TreeNode * SubtreeRoot, DateType& data);
	//This supports the implementation of the DeleteNode method above.
	// Find the predecessor of the root node in SubtreeRoot.
	// If there is one, return true and store the predecessor data in data
	//Otherwise, return false.



	 //int Size();	//To be implemented in a future assignment				
	 //Return the number of elements in the linked list.   

	 
     //void FindAndDisplay(int v1, int v2);	//To be implemented in a future assignment				
	 //Display the all the values between v1 and v2 that are currecntly 
	 //stored in the Value field of all ListNode structures in the linked list.


	//*******************************************************************
	//The following two global I/O operators are declared as friends
	//*******************************************************************

	friend ostream & operator<< (ostream & output, Tree & aTree);
	//Writing out the integer values currently stored in the Tree "aTree"
	//into the ostream object "output", which may represent a file or just cout.

	friend istream & operator>> (istream & input, Tree & aTree);
	//Clear and empty the current list.
	//Read int values from the istream object "input", which may represent a file or just cin 
	//and then store them into the Tree "aTree".
	
 };

#endif
