//#include<bits/stdc++.h> //Contains all STL functions
#include <iostream>
#include <vector> //For vectors
#include <algorithm>
#include <utility> //For pairs

using namespace std;

int main()
{
    // Pairs

    // pair<int,string> p;
    // p = make_pair(3,"Hi");
    // //p = {3,"Hello"}; -- Other way than make_pair
    // cout<<p.first<<" "<<p.second<<endl;

    // cout<<"Enter value of pair";
    // cin>>p.first>>p.second;
    // cout<<p.first<<" "<<p.second<<endl;

    // pair<int,string> &p1 = p; //passing p in reference
    // p1.first = -1;
    // cout<<p1.first<<endl;

    // pair<int,int> parr[3]; //Array of pair - 3 pairs 


    // Vectors

    // vector<int> v; //size 0 
    // v.push_back(2); //Add element to last index of vector(push)
    // //v.emplace_back(3); //Add element to last index of vector(push)
    // cout<<v.size()<<" "<<v[0]<<endl;

    // vector<int> v1(5); //size 5 -> all initialised to 0
    // for(int i=0;i<v1.size();i++)
    // {
    //      cout<<v1[i]<<endl;
    // }

    // vector<int> v2(5,3); //size 5 -> all initialised to 3
    // for(int i=0;i<5;i++)
    // {
    //     cout<<v2[i]<<" Size is: "<<v2.size()<<endl;
    //     v2.pop_back(); //Pop element
    // }
    // cout<<v2.size(); //It will be 0

    //Nested Vectors

    // vector<pair<int,string> > v(3);//Vector of pairs of size 3
    // cout<<"Enter values to input\n";
    // for(int i=0;i<v.size();i++)
    // {
    //     cin>>v[i].first>>v[i].second;
    // }
    // cout<<v[0].first<<" "<<v[2].second;

    // // Iterators -- Traverse through containers
    // vector<int>v3(5,7);
    // // conatiner :: iterator iterator_name
    // vector<int> :: iterator it;
    // for(it = v3.begin();it<v3.end();it++)
    // {
    //     cout<<(*it)<<endl;
    // }
    // //Accessing vector of pairs using iterator
    // // vector<pair<int,string>> v_p ={(1,"Ram"), (2,"Sham")};
    // // vector<pair<int,string>> :: iterator it1;
    // // for(it = v_p.begin();it<v_p.end();it+1)
    // // {
    // //     cout<<*it1.first<<" "<<it1->second<<endl;
    // // }

    //Short way to use iterator by using auto keyword
    vector<int> v4(4,8);
    for(auto it = v4.begin();it<v4.end();it++)
    {
        cout<<(*it)<<endl;
    }

    

    







}