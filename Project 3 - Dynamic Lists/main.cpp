// Programmer: Dylan Phelps
// Project Number: 3
// Project Desc: List class with Resizable Dynamic Array
// Course: Data Structures
// Date: Feb 23, 2014

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
using namespace std;
#include "DList.h"

// PROTOTYPES:
void print_menu( );
// Postcondition: A menu of choices has been printed.

int get_number(string prompt );
// Postcondition: The user has been prompted to enter an integer number. The
// number has been read, echoed to the screen, and returned by the function.

char get_user_command( );

int main( )
{
    List test;     // A List to perform tests on
    char choice;   // Command entered by the user

    cout << "I have initialized an empty list of integers." << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));

        switch (choice)
        {
            case 'A': test.populate(get_number("Enter a number: "));// add code to add n integers to end of list
                      break;
            case 'C': test.resize(get_number("Enter list capacity: "));// add code to change the capacity of the list
                      break;
            case 'E': cout << test.empty();// add code to print result of empty( )
                      break;
            case 'P': test.display(cout);// add code to print the list
                      break;
            case 'I': test.insert(get_number("Enter an item: "), get_number("Enter a position: "));// add code to input an item and position, and insert item into the list
                      break;
            case 'R': test.erase(get_number("Enter a position: "));// add code to input a position, and erase the item at that position
                      break;
            case 'Q': cout << "Test program ended." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu( )
{
    cout << endl;
    cout << "The following choices are available: " << endl;
    cout << " A   Add a number of random integers to end of list" << endl;
    cout << " C   Change the capacity of the list using resize( )" << endl;
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print a copy of the entire list" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " R   Remove a number with the erase( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

int get_number(string prompt)
// Library facilities used: iostream
{
    int result;

    cout << prompt;
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}
