#include <cassert>
#include <new>
#include <cstdlib>
using namespace std;

#include "List.h"

//--- Definition of class constructor
List::List( )
:first(0), mySize(0)
{

}
//--- Definition of copy constructor
List::List( const List &source ){
    mySize = source.mySize;                     //set size equal to size of the source list
    first = 0;
    if (mySize == 0) return;                    //If size is 0 then list is empty; nothing else to do
    List::NodePointer srcPtr,ptr;
    first = new Node(source.first->data);       //copy first node of src list into first node
    ptr = first;
    srcPtr = source.first->next;                //src pointer points to the next node to be copied
    while (srcPtr != 0)
    {
        ptr->next = new Node(srcPtr->data);     //src node is copied into the next node
        srcPtr = srcPtr->next;                  //src pointer points to the next node to be copied
        ptr = ptr->next;                        //ptr points to the next node to be copied to
    }
}
//--- Definition of destructor
List::~List( ){
   List::NodePointer rm = first, ptr;
   while (rm != 0){
        ptr = rm -> next;       //ptr points to next node
        delete rm;              //delete node rm is pointing to
        rm = ptr;               //set rm to the next node stored by ptr
   }
}
//--- Definition of assignment operator
const List & List::operator=( const List &rightSide ){
    mySize = rightSide.mySize;                          //set size equal to size of the source list
    first = 0;
    if (mySize == 0) return *this;                      //If size is 0 then list is empty; nothing else to do
    if (this != &rightSide)
    {
        this->~List();                                  //Deconstruct the list
        List::NodePointer srcPtr, ptr;
        first = new Node(rightSide.first->data);        //Copy the first node
        ptr = first;                                    //Have ptr point to the first node
        srcPtr = rightSide.first->next;                 //Move on to the next node to be copied over
        while (srcPtr != 0){
            ptr->next = new Node(srcPtr->data);         //src node is copied into the next node
            srcPtr = srcPtr->next;                      //src pointer points to the next node to be copied
            ptr = ptr->next;                            //ptr points to the next node to be copied to
        }
    }
    return *this;
}
//--- Definition of getSize()
int List::getSize( ) const{
    return mySize;
}
//--- Definition of empty()
bool List::empty( ) const{
    return mySize == 0;
}
//--- Definition of insert()
void List::insert( ElementType dataVal, int index ){
    assert(0 <= index && index <= mySize);
    mySize++;
    List::NodePointer newPtr = new Node(dataVal),   //create new node and store dataVal
    predPtr = first;

    if (index == 0){
        newPtr -> next = first;                     //move the current first node over one
        first = newPtr;                             //set first to point to the new node
    } else {
        for (int i = 1; i < index; i++){
            predPtr = predPtr -> next;
            newPtr -> next = predPtr -> next;       //insert newPtr node into list
            predPtr -> next = newPtr;               //reset link in node pointed to by predPtr equal to node pointed to by newPtr
        }
    }
}
//--- Definition of erase()
void List::erase( int index ){
    assert(0 <= index && index < mySize);
    mySize--;
    List::NodePointer ptr, predPtr = first;
    if (index == 0){
        ptr = first;                        //ptr points to node to be deleted
        first = predPtr -> next;            //set first equal to the next node in order to fill gap
        delete ptr;                         //return node pointed to by ptr to storage pool
    } else{
        for(int i = 1; i < index; i++){
            ptr = predPtr -> next;
            predPtr -> next = ptr -> next;  //set node referred to by predPtr = node pointed to by ptr
            delete ptr;                     //return node pointed to by ptr to storage pool
        }
    }
}
//--Definition of display()
void List::display( ostream &out ) const{
    List::NodePointer ptr = first;           //create pointer to point to each node
    while(ptr != 0){
        out << ptr -> data << " ";          //print out value of node that ptr is pointing at
        ptr = ptr -> next;                  //set ptr to point to next node
    }
}
//--- Definition of find()
int List::find( ElementType value) const{
    List::NodePointer ptr = first;
    int index = 0;
    while(ptr != 0){
        if(ptr -> data == value){           //If value of is found, return the index of that value
            return index;
        }
        index++;
        ptr = ptr -> next;                  //Move to the next node to be checked
    }
    index = -1;                             //If value is not found, return -1
    return index;
}
