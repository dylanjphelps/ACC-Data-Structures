// Programmer: Dylan Phelps
// Project Number: 4
// Project Desc: Linked-list Processing
// Course: Data Structures
// Date: March 3, 2014

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <string>
using namespace std;
#include "List.h"

// PROTOTYPES:
void print_menu( );
// Postcondition: A menu of choices has been printed.

int get_number(string prompt );
// Postcondition: The user has been prompted to enter an integer number. The
// number has been read, echoed to the screen, and returned by the function.
string get_user_num( );

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
            case 'E': cout << test.empty();
                      break;
            case 'P': test.display(cout);
                      break;
            case 'I': test.insert(get_user_num( ), get_number("Enter a position: "));
                      break;
            case 'R': test.erase(get_number("Enter an index to be removed: "));
                      break;
            case 'F': cout << test.find(get_user_num( ));
                      break;
            case 'S': cout << test.getSize();
                      break;
            case 'Q':
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
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print a copy of the entire list" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " R   Remove a number with the erase( ) function" << endl;
    cout << " F   Find a value in the list with the find() function" << endl;
    cout << " S   Print the result from the getSize() function" << endl;
    cout << " Q   Quit this test program" << endl;
}

string get_user_num( )
// Library facilities used: iostream
{
    string command;

    cout << "Enter an item: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
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

