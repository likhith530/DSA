#include<string>
#include<iostream>
using namespace std;
class Solution {
     isPalindrome(string s) {
        string s1;
        int len= s.length;
        int i,j;
        for(i=0,j=0;i<len;i++,j++)
        {
            if(s[i]>97 && s[i]<122 || s[i]>65 && s[i]<90)
            {
                s1[j]=s[i];
                s1[j]= tolower(s1[j]);
            }
        }
        int end = s1.length -1;
       for(i=0,end;i<j;i++,end--)
       {
           if(s1[i]==s1[j])
            return 1;
            else 
            return 0;
       }    
    }
};