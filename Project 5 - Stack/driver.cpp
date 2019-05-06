// Programmer: Dylan Phelps
// Project Number: 5
// Project Desc: Evaluating Postfix Expressions
// Course: Data Structures
// Date: March 25, 2014
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include "LStack.h"

using namespace std;

int main(){
    int evaluate(string exp);
    bool checkEqu(string exp);

    string postfix;
    char user_input;

    do{

        cout << "\nEnter postfix expression:" << endl;
        if ( cin.peek() == '\n' ){
            cin.ignore();
        }
        getline(cin, postfix);
        //If postfix expression is valid evaluate, otherwise print error message
        if (checkEqu(postfix)){
            cout << "The value of the expression is " << evaluate(postfix) << endl;
        }else {cerr << "***MALFORMED POSTFIX EXPRESSION***" << endl;}

        cout << "\nMore expressions (Y or N)? ";
        cin >> user_input;
        user_input = tolower(user_input);

    }while(user_input=='y');


    return 0;
}

//Evaluates the result of the postfix function.
int evaluate(string exp){
    Stack s;
    char token;
    int value;

    for (unsigned int i = 0; i < exp.length(); i++){

            token = exp[i];
            switch(token){
            case ' ': break;
            case '+': value = s.top(); s.pop(); value += s.top(); s.pop(); s.push(value); break;
            case '-': value = s.top(); s.pop(); value = s.top()-value; s.pop(); s.push(value); break;
            case '*': value = s.top(); s.pop(); value *= s.top(); s.pop(); s.push(value); break;
            case '/': value = s.top(); s.pop(); value = s.top()/value; s.pop(); s.push(value); break;
            default: s.push(token-48); break;
        }
    }
    return value;
}

//Returns true if the postfix function is valid, false if not
bool checkEqu(string exp){
    bool proper;
    char token;
    int operand = 0;
    int op = 0;

    for (unsigned int i = 0; i < exp.length(); i++){
        token = exp[i];
        switch(token){
            case ' ': break;
            case '+': case '-': case '*': case '/': op++; break;
            default: operand++; break;
        }
    }
    proper = (operand-1) == op;
    return proper;
}
