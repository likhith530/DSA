#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 1; //Max Number of graoh possible
vector<int> graph[N];
int height[N];
int depth[N];
void dfs(int vertex , int parent)
{
    for(int child : graph[vertex])
    {
        if(child == parent) continue;
        depth[child] = depth[vertex] + 1; //Parent depth + 1 -- while going down (2)
        dfs(child,vertex);
        height[vertex] = max(height[vertex] , height[child] + 1);
        //While going up (3)
    }
}
int main()
{
    //Tree -> n vertices , n-1 edges 
    int n;
    cout<<"Enter Number of Vertices\n";
    cin>>n;
    for(int i=0;i<n-1;i++) //Inputing for all n-1 vertices
    {
        int v1, v2;
        cin>>v1>>v2;
        g[v1].push_back(v2); //Undirected graph
        g[v2].push_back(v1);
    }
    dfs(1,0);
    for(int i=1; i<=n;i++)
    {
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
}