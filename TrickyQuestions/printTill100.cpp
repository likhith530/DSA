/*
    Print numbers from 1 to 100 , without Loop , without Recursion

    Methods to solve :-
    1. With Goto statements -> (If this is not allowed then 2)
    2. Create 100 objects , each object calls the function Print , which uses a
    static variable count that will be incremented and printed
*/


/*
Key Learnings :- 
- Static variables are class variables and can be used among multiple objects 
- So, Static variable's memory will be kept in class memory
- Object memory will have instance variables
- So we cant count using instance variables , as each object will have its 
    copy and will not maintain updated value of count
- Static variable vcan be only used inside class
*/

#include <iostream>

using namespace std;

class Print {
    static int count; // Declaration of the static member variable
public:
    Print(); 
};

int Print::count = 0; // Definition and initialization of the static variable

Print::Print() {
    count++;
    cout << count << " ";
}

int main() {
    Print A[100]; // Create an array of 100 Print objects
    return 0;
}

