#include<stdio.h>
void get(int);
//int c1=0,c2=0;
 void get(int n)
    {
        if(n<1) return;
        get(n-1); 
        //c1++;}
        get(n-3); 
        //c2++;}
        printf("%d ",n);
    }
int main()
{
    get(3);
    //printf("%d %d ",c1,c2);
    return 0;
}