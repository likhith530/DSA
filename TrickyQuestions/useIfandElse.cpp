/*
We have to use both if and else inside a block 
- key idea , we have to loop back to do this -> so loop or goto
*/


#include<bits/stdc++.h>
using namespace std;

class Demo{
public:
    void solve()
    {
        int x = 5;
        while(x-- > 0)
        {
            if(x>3) cout<<"If Printed"<<endl;
            else cout<<"Else Printed"<<endl;
        }
    }
};

int main(){
    Demo ob; //Creates ob on Stack
    ob.solve();
    // Demo *ob1 = new Demo(); -> new Demo() --> Creates object on Heap
    // ob1->solve();
    return 0;
}

/*

Static local variable = class variables
Visibility: class
Lifetime: till termination of program
Default value:0
Storage:heap

Local Variable
Visibility: class
Lifetime: until execution of class
Default value:garbage
Storage:stack

Global variable
Visibility: file
Lifetime: till termination of program
Default value:0
Storage:heap

*/