#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1; //Max Number of graph possible
vector<int> g[N]; //Adjacency List of Max size

void bfs(int vertex , int vis[]){
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 1;
    cout<<"Source Vertex:"<<vertex<<endl; //Printing the source vertex
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int child :g[cur]){ //Traversing through the children of cur vertex
            if(vis[child] == 0){
                cout<<"Parent vertex: "<<cur<<" Child Vertex: "<<child<<endl;        
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n,m;
    cout<<"Enter Number of Vertices and Edges\n";
    cin>>n>>m;
    int vis[n+1]; //Visited array for all vertices marked as 0
    for(int i=0;i<m;i++) //Inputing vertices for m edges
    {
        int v1, v2;
        cin>>v1>>v2;
        g[v1].push_back(v2); //Undirected graph
        g[v2].push_back(v1);
    }

    for(int i=0;i<=n;i++)
    {
        vis[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i] == 0)
            bfs(i,vis);
    }
}
/*
0 1
0 2
1 3 
2 4

*/
/* 
0 2
2 1
4 3
*/
