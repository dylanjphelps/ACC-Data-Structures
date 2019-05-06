/*-- DList.cpp-----------------------------------------------------------

   This file implements List member functions.
-------------------------------------------------------------------------*/

#include <cassert>
#include <new>
#include <cstdlib>
using namespace std;

#include "DList.h"

//--- Definition of class constructor
List::List(int maxSize)
: mySize(0), myCapacity(maxSize)
{
   myArray = new ElementType[maxSize];  // program will abort if
                                        // allocation fails
}

//--- Definition of class destructor
List::~List()
{
   delete [] myArray;
}

//--- Definition of copy constructor
List::List(const List & origList)
: mySize(origList.mySize), myCapacity(origList.myCapacity)
{
  //--- Get new array for copy
   myArray = new ElementType[myCapacity];  // program will abort if
                                           // allocation fails

      //--- Copy origList's elements into this new array
      for(int i = 0; i < mySize; i++)
         myArray[i] = origList.myArray[i];

}

//--- Definition of assignment operator
const List & List::operator=(const List & rightHandSide)
{
   if (this != &rightHandSide)  // check that not self-assignment
   {
      //-- Allocate a new array if necessary
      if (myCapacity != rightHandSide.myCapacity)
      {
         delete[] myArray;
         myCapacity = rightHandSide.myCapacity;
         myArray = new ElementType[myCapacity];  // program will abort if
                                                 // allocation fails

      }
      //--- Copy rightHandSide's list elements into this new array
      mySize = rightHandSide.mySize;
      for(int i = 0; i < mySize; i++)
         myArray[i] = rightHandSide.myArray[i];
   }
   return *this;
}

//--- Definition of empty()
bool List::empty() const
{
   bool empty = true;
   if (mySize != 0){
        empty = false;
   }
   return empty;
}

//--- Definition of display()
void List::display(ostream & out) const
{
   for (int i = 0; i < mySize; i++)
     out << myArray[i] << "  ";
}

//--- Definition of output operator
ostream & operator<< (ostream & out, const List & aList)
{
   aList.display(out);
   return out;
}

//--- Definition of insert()
void List::insert(ElementType item, int pos)
{
   assert( pos >= 0 && pos <= mySize ); // is insert position legal?

   // If there is not room for new elements, double the size of the list
   if (mySize == myCapacity){
        mySize = 2*mySize;
        resize(mySize);
   }

   // First shift array elements right to make room for item

   for(int i = mySize; i > pos; i--)
      myArray[i] = myArray[i - 1];

   // Now insert item at position pos and increase list size
   myArray[pos] = item;
   mySize++;
}

//--- Definition of erase()
void List::erase(int pos)
{
   assert( !empty() );
   assert( pos >= 0 && pos < mySize ); // is delete position legal?

   // Shift array elements left to close the gap
   for(int i = pos; i < mySize; i++)
       myArray[i] = myArray[i + 1];

   // Decrease list size
    mySize--;
}

//--- Definition of resize()
void List::resize( int newCapacity){
    if(newCapacity < mySize){
       newCapacity = mySize;
    }
    if(newCapacity == mySize){
        return;
    }
    //Allocate a new dynamic array with the new capacity
    ElementType * newArray;
    newArray = new(nothrow) ElementType[newCapacity];
    //Copy elements of the original array to the new one
    for(int i = 0; i < mySize; i++ ){
        newArray[i] = myArray[i];
    }
    //Free memory allocated by the old array
    delete [] myArray;
    //Make the list point to the new array
    myArray = newArray;
    //Update capacity of the list
    myCapacity = newCapacity;
}

//--- Definition of populate
void List::populate(int num){
    resize(mySize+num);
    for(int i = mySize; i < num+mySize; i++){
        myArray[i] = rand()%999+1;
    }
    mySize = mySize+num;
}


