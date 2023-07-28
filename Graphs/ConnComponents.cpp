#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 1; //Max Number of graoh possible
vector<int> graph[N];
bool vis[N]; //We can take bool or int

vector<vector<int> > cc; //connected components
vector<int> current_cc; //Current connected component
void dfs(int vertex)
{
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for(int child : graph[vertex])
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
        graph[v1].push_back(v2); //Undirected graph
        graph[v2].push_back(v1);
    }
    int cnt =0;
    for(int i=1 ; i<=n;i++)
    {
        if(vis[i] == false) //If not visited call dfs
        {
            current_cc.clear(); //empty old component
            dfs(i);
            cnt++;
            cc.push_back(current_cc); //As this component dfs call has been done 
        }
    }
    cout<<"Number of Connected Components is "<<cnt<<endl;
    cout<<"The Connected Components are:\n";
    for(auto curr_cc : cc )
    {
        for(int ele : curr_cc)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}