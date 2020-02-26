#include "Tree.h"


Tree :: Tree()
{
   Root = nullptr;
}


Tree :: ~Tree()
{
 DeleteCompleteTree(Root);
}

void Tree :: Clear()
{
 DeleteCompleteTree(Root);
 Root = nullptr;
}

void Tree :: Insert(int Val)
{
  InsertTree(Root, Val);
}


void Tree :: InsertTree(TreeNode * & SubtreeRoot, int Val)
{
   if (SubtreeRoot==nullptr)
   {
    SubtreeRoot= new TreeNode;
    SubtreeRoot->Left=nullptr;
    SubtreeRoot->Right=nullptr;
    SubtreeRoot->Value = Val;
    return;
   }
// handle duplicate
   if (Val == SubtreeRoot->Value)
     return;

   //search Left
   if (Val < SubtreeRoot->Value)
     InsertTree(SubtreeRoot->Left, Val);

   //search Right
   else
     InsertTree(SubtreeRoot->Right,Val);
}


void Tree::Display()
{
 cout << endl << "Contents in the tree:" << endl;
 DisplayTree(Root);
 cout << endl;
}


void Tree :: DisplayTree(TreeNode * SubtreeRoot)
{
 if (SubtreeRoot != nullptr)
   {
    DisplayTree(SubtreeRoot->Left);
    cout<<SubtreeRoot->Value << endl;
    DisplayTree(SubtreeRoot->Right);
   }
}

void Tree::Write(ostream & output)
{
 WriteTree(output, Root);
 cout << endl;
}

void Tree :: WriteTree(ostream & output, TreeNode * SubtreeRoot)
{
 if (SubtreeRoot != nullptr)
   {
    WriteTree(output, SubtreeRoot->Left);
    output << SubtreeRoot->Value << endl;
    WriteTree(output, SubtreeRoot->Right);
   }
}

bool Tree:: Search(int Val)
{
   return SearchTree(Root, Val);
}


bool Tree:: SearchTree(TreeNode * SubtreeRoot, int Val)
{
   if (SubtreeRoot == nullptr)
     return false;
   if (SubtreeRoot->Value == Val)
     return true;
   if (Val < SubtreeRoot->Value)
     return SearchTree(SubtreeRoot->Left, Val);
   return SearchTree(SubtreeRoot->Right, Val);
}


void Tree :: DeleteCompleteTree(TreeNode * SubtreeRoot)
{
 if (SubtreeRoot != nullptr)
   {
    DeleteCompleteTree(SubtreeRoot->Left);
    DeleteCompleteTree(SubtreeRoot->Right);
    delete SubtreeRoot;
   }
}


//************************************************************
// The following are three global functions as additional Code
// 	used to support the deletion of a node from a tree
//		Not in the book
//***************************************************



bool Tree::GetPredecessor(TreeNode * SubtreeRoot, int& data)
// Find the predecessor of the root node in SubtreeRoot.
// If there is one, return true and store the predecessor data in data
//Otherwise, return false.
{
  if (SubtreeRoot == nullptr || (SubtreeRoot->Left) == nullptr)
	  return false;

 TreeNode * temp = SubtreeRoot->Left;
  while (temp->Right != nullptr)
    temp = temp->Right;

  data = temp->Value;
  return true;
}


void Tree::DeleteItem(TreeNode *& SubtreeRoot, int item)
// Deletes item from tree.
// Post:  item is not in tree rooted at SubtreeRoot.
{
  if (SubtreeRoot == nullptr)
	return;

  if (item < SubtreeRoot->Value)
    DeleteItem(SubtreeRoot->Left, item);         // Look in Left subtree.
  else if (item > SubtreeRoot->Value)
    DeleteItem(SubtreeRoot->Right, item);        // Look in Right subtree.
  else
    DeleteNode(SubtreeRoot);                 // Node found; call DeleteNode.

}

void Tree::DeleteNode(TreeNode *& SubtreeRoot)
// Deletes the node pointed to by SubtreeRoot.
{

  if (SubtreeRoot == nullptr)
	return;
  //cout << "To delete " << tree->Value << endl;

  if (SubtreeRoot->Left != nullptr  && SubtreeRoot->Right != nullptr)
  { int data;
    GetPredecessor(SubtreeRoot, data);
    SubtreeRoot->Value = data;
    DeleteItem(SubtreeRoot->Left, data);       // Delete predecessor node.
  }
  else
  {
	TreeNode * tempPtr;
	tempPtr = SubtreeRoot;

	if (SubtreeRoot->Left == nullptr)
		SubtreeRoot = SubtreeRoot->Right;
	else if (SubtreeRoot->Right == nullptr)
		SubtreeRoot = SubtreeRoot->Left;
	delete tempPtr;
  }
}




//*****************************************************************
// The following is an additional member function of the Tree class.
// 	It directly or indirectly uses the three functions above to
//	delete an item from the tree.
//		Not in the book
//***************************************************


void Tree::Delete(int item)
// Calls recursive function Delete to delete item from tree.
{
  DeleteItem(Root, item);
}





//Clear and empty the current tree.
//Read int values from the istream object "input", which may represent a file or just cin 
//and then store them into the Tree "aTree".
//
istream & operator>> (istream & input, Tree & aTree)
{
	int n;
	if (&input == &cin)
	{
		n = -1;
		while (n < 0)
		{
			cout << "How many elements to add into the linked list?";
			cin >> n;
		}

		aTree.Clear();

		cout << endl << "Enter them one by one" << endl;
		for (int i=0; i<n; i++)
		{	int temp;
			cout << "[" << i << "]:";
			cin >> temp;
			aTree.Insert(temp);
		}
	}

	else // (&input != &cin)
	{
		input >> n;
		if (n >= 0)
			aTree.Clear();
		else
			return input;


		for (int i=0; i<n; i++)
		{	int temp;
			input >> temp;
			aTree.Insert(temp);
		}
	}

	return input;

}


//Writing out the integer values currently stored in the Tree "aTree"
//into the ostream object "output", which may represent a file or just cout.
ostream & operator<< (ostream & output, Tree & aTree)
{

	if (&output == &cout)
		aTree.Display();

	else //(output != cout)
		aTree.Write(output);

	return output;
}

