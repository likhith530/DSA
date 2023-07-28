#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 1; //Max Number of graoh possible
vector<int> graph[N];
bool vis[N]; //We can take bool or int
void dfs(int vertex)
{
    vis[vertex] = true;
    for(int child : vertex)
    {
        if(vis[child])
            continue;
        dfs(child);
    }
}

int main()
{
    int n,m;
    cout<<"Enter Number of Vertices and Edges\n";
    cin>>n>>m;
    for(int i=0;i<m;i++) //Inputing vertices for m edges
    {
        int v1, v2;
        cin>>v1>>v2;
        g[v1].push_back(v2); //Undirected graph
        g[v2].push_back(v1);
    }
    int cnt =0;
    for(int i=1 ; i<=n;i++)
    {
        if(vis[i] == false) //If not visited call dfs
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<"Number of Connected Componebts is "<<cnt<<endl;
}