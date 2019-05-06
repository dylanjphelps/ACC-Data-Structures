// Programmer: Dylan Phelps
// Project Number: 6
// Project Desc: Trees
// Course: Data Structures
// Date: April 16, 2014

#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and empty()
   BST<int> intBST;            // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing inorder
   cout << "Inorder Traversal of BST: \n";
   intBST.inorder(cout);

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
   }
   intBST.graph(cout);

   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";
   cout << "Inorder Traversal of BST: \n";
   intBST.inorder(cout);

   cout << endl;

   cout << "Height: " << intBST.getHeight() << endl;
   cout << "Count : " << intBST.getLeafCount() << endl;

   return 0;
}
