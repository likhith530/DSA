#include <iostream>
#include <vector> //For vectors
#include <algorithm>
#include <utility> //For pairs
#include <map> //For ordered maps
#include <unordered_map> //For unordered maps
#include <set> //For sets and multi sets
#include <unordered_set> //For unordered sets
using namespace std;
int main()
{
    //Maps
    map<int,string>m;
    m[1] ="abc";
    m[3] = "bcd";
    m[6] = "cde";
    m[2] = "ghi";
    //Each element in a map is a pair -- Traversing using iterator
    //auto i means it is dynamically stored + i will have value(for each loop type)
    for(auto pr : m)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    // Or :-
    map<int,string>:: iterator it;
    for(it = m.begin();it!= m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
        //or
        //cout<<*it.first<<" "<<*it.second<<endl;
    }
    // auto it1 = m.find(7); --searches the value for given key and returns iterator
    // cout<<it1<<endl;

    //m.clear(); -- deletes the map

    unordered_map<char,int> m3;
    m3['a'] = 97;
    m3['A'] = 65;
    m3['d'] = 100;
    m3['B'] = 66;
    cout<<m3['a']<<endl;


    set<string> s; //Sorted elements + unique
    s.insert("ramesh"); // O(log N) time
    s.insert("Suresh");
    s.insert("Kamlesh");

    for(string i : s)
    {
        cout<<i<<endl;
    }

    for(auto it = s.begin(); it!= s.end() ;it++)
    {
        cout<<*it<<endl;
    }

    auto it = s.find("ramesh");
    cout<<*it<<endl; //returns iterator value i.e searched value

    s.erase(it);

    s.erase("Suresh");

    for(string i : s)
    {
        cout<<i<<endl; //only kamlesh is left
    }

    unordered_set<int> u_s; //non sorted way + unique 
    u_s.insert(30); // O(1) time
    u_s.insert(40);
    u_s.insert(20);
    for(int i : u_s)
    {
        cout<<i<<endl;
    }

    for(auto it = u_s.begin(); it!= u_s.end() ;it++)
    {
        cout<<*it<<endl;
    }

    auto it = u_s.find(50); //O(1) time
    if(u_s.end() == it)
    {
        cout<<"Element not found , so iterator is pointing out";
    }

    
    multiset<string> name; // set with non unique values
    name.insert("Likhith");
    name.insert("Jay");
    name.insert("Shah");
    name.insert("Likhith");
    name.insert("Shah");

    for(string n : name)
    {
        cout<<n<<endl;
    }

    for(auto it3 = name.begin(); it3!= name.end() ;it3++)
    {
        cout<<*it3<<endl;
    }

    auto it = name.find("Likhith");
    cout<<*it<<endl;

    name.erase(it); //Only 1 Likhith is erased i.e that iterator is erased

    name.erase("Shah"); //All Shah erased as value is removed

    cout<<"After erasing: \n";
    for(string n : name)
    {
        cout<<n<<endl;
    }

    //Program to find the frequency of strings and store lexographically in given N strings -- map
    //We can use value as frequency (int) and key as strings

    //Program to find the frequency of strings in given N strings -- unordered map
    //We can use value as frequency (int) and key as strings

    //Program to find all the unique strings in lexographical order from given N strings -- set
    
    //Program to find if in N strings , the asked query of strings are present or not -- unordered set
    return 0;
}