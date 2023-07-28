#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 1; //Max Number of graoh possible
vector<int> g[N]; //Adjacency List of Max size

int subtree_sum[N];
int even_count[N];

void dfs(int vertex , int parent)
{
    //Action on 'vertex' after entering given vertex
    for(int child : g[vertex])
    {
        //Action on 'child' vertices before entering the child node
        if(child == parent) continue;//Or the above '*' line 
        dfs(child,vertex);
        //Action on 'child' vertices after exiting the child node
        //Subtree Sum -> while coming up
        subtree_sum[vertex] += subtree_sum[child]; //Added all child
        even_count[vertex] += even_count[child];
    }
    subtree_sum[vertex] += vertex; //Adding itself
    if(vertex%2 ==0)    even_count[vertex]++;
    //Action on 'vertex' after exiting given vertex
}

int main()
{
    int n;
    cout<<"Enter Number of Vertices\n";
    cin>>n;
    for(int i=0;i< n-1;i++) //Inputing vertices for n-1 edges
    {
        int v1, v2;
        cin>>v1>>v2;
        g[v1].push_back(v2); //Undirected graph
        g[v2].push_back(v1);
    }
    dfs(1,0); //Calling once for precomputation
    int q; //No of Queries
    cout<<"Enter the number of queries\n";
    cin>>q;
    while(q--){
        int v;
        cin>>v;
        cout<<"Subtree Sum of "<<v<<" is :"<<subtree_sum[v]<<endl;
        cout<<"The Number of even nodes of "<<v<<" is :"<<even_count[v]<<endl;
    }

}