#include "Tree.h"

void main()
{
   Tree T;

   T.Insert(45);
   T.Insert(20);
   T.Insert(1);
   T.Insert(100);
   T.Insert(30);
   T.Insert(17);
   T.Insert(110);
   T.Display();

   if (T.Search(100))
     cout<<"FOUND\n";
   if (!T.Search(50))
     cout<<"NOT FOUND\n";
    cout<<endl << endl << endl;


   T.Delete(45);
   T.Delete(45);
   T.Delete(97);
   T.Display();

   char X;
   cin >> X;


}
