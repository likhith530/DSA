#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 1; //Max Number of graoh possible
vector<int> g[N]; //Adjacency List of Max size

void dfs(int vertex , int vis[])
{
    //Action on 'vertex' after entering given vertex
    cout<<vertex<<endl;
    //if(vis[vertex] == 1)    return; // '*' Exit from that recusion as it is visited
    vis[vertex] = 1;
    for(int child : g[vertex])
    {
        //Action on 'child' vertices before entering the child node
        cout<<"Parent vertex: "<<vertex<<" Child Vertex: "<<child<<endl;
        if(vis[child] == 1) continue; //Or the above '*' line 
        dfs(child,vis);
        //Action on 'child' vertices after exiting the child node
    }
    //Action on 'vertex' after exiting given vertex
}
//O(V+E) -- V recursion calls and for each V , an edge is called (So all finally edges are called)
int main()
{
    int n,m;
    cout<<"Enter Number of Vertices and Edges\n";
    cin>>n>>m;
    int vis[n]; //Visited array for all vertices marked as 0
    for(int i=0;i<m;i++) //Inputing vertices for m edges
    {
        int v1, v2;
        cin>>v1>>v2;
        g[v1].push_back(v2); //Undirected graph
        g[v2].push_back(v1);
    }
    dfs(0,vis);
}

