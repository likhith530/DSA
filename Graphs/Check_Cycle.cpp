#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 1; //Max Number of graoh possible
vector<int> graph[N];
bool vis[N]; //We can take bool or int


bool dfs(int vertex , int parent)
{
    vis[vertex] = true;
    bool isCycleExists = false;
    for(int child : graph[vertex])
    {
        if(vis[child] && child == parent) //Visited and it is parent , ignore
            continue;
        if(vis[child]) //visited and it is non parent -> so loop exists
            return true;
        isCycleExists = isCycleExists || dfs(child , vertex); // If any one dfs call is true -> cycle exists
        //As parent for child is vertex -->dfs(child , vertex)
    }
    return isCycleExists;
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
        graph[v1].push_back(v2); //Undirected graph
        graph[v2].push_back(v1);
    }
    int cnt =0;
    for(int i=1 ; i<=n;i++)
    {
        if(vis[i] == false) //If not visited call dfs
        {
            if(dfs(i,0) == true) //Pass 0 as parent for first node (i.e No parent)
            {
                cout<<"Loop Exists"<<endl;
                break;
            }
        }
    }
}