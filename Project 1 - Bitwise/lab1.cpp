// Programmer: Dylan Phelps
// Project Number: 1
// Project Desc: Binary Representations of Data
// Course: Data Structures
// Date: Jan. 26, 2014

#include <iostream>
#include "lab1.h"

using namespace std;

int main(){
    int choice;     //Used to store user choice from menu
    char c;         //Stores user input character
    short s;        //Stores user input short
    float f;        //Stores user input float

    //Display instructions for user
    cout << "\nMenu:" << endl;
    cout << "1 - Print the binary representation of a character" << endl;
    cout << "2 - Print the binary representation of a short integer" << endl;
    cout << "3 - Print the binary representation of a float" << endl;
    cout << "4 - Exit program" << endl;

    while (choice != 4){

        cout << "\nEnter your choice: ";
        cin >> choice;

        //Switch takes the user input choice and executes the corresponding function
        switch(choice){
            case 1: cout << "\nEnter a character: "; cin >> c; cout << "\nThe binary representation for " << c << " is:"; printChar(c); break;
            case 2: cout << "\nEnter a short: "; cin >> s; cout << "\nThe binary representation for " << s << " is:"; printShort(s); break;
            case 3: cout << "\nEnter a float: "; cin >> f; cout << "\nThe binary representation for " << f << " is:"; printFloat(f); break;
            case 4: break;
            default: cout << "The value you entered is invalid. Please try again..." << endl;
        }
    }
    cout << "Exiting program...";
}


