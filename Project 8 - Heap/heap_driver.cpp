// Programmer: Dylan Phelps
// Project Number: 8
// Project Desc: Heap
// Course: Data Structures
// Date: May. 1, 2014
//Unfortunatley I was not able to get the code to run using a dynamic array.
//I was only able to get the sort to work using a pre-initialized list.

#include <iostream>

using namespace std;

#include "heap.h"

int main(){

    char cont = 'Y';

    int size;
    do{
            cout << "Enter the size of the list: " << endl;
            cin >> size;

            size++;

            int * num_list = new int[size];
            //int num_list[]= {0,35,15,77,60,22,41};

            for(int i = 1; i < size; i++){
                cout << "Enter a value for location " << i << ": " << endl;
                cin >> num_list[i];
            }


            for(int i = 1; i < size; i++){
                cout << num_list[i] << " ";
            }
            cout << endl;

            heapify(num_list, size);

            for(int i = 1; i < size; i++){
                cout << num_list[i] << " ";
            }
            cout << endl;

            delete [] num_list;

            cout << "Continue? Y or N: " << endl;
            cin >> cont;
            cont = toupper(cont);

    }while(cont == 'Y');

    return 0;
}
