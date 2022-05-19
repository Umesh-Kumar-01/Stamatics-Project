#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5+10;
bool vis[N];    // visited array 
vector<int> v1[N]; // declaration of adjacency list 

vector<int> time_in(N,0);   // In time vector
vector<int> time_out(N,0); // Out time vector

int crt_time =0; // set current time = 0

// define struct for edge
struct edge
{
    int start;
    int end;
};

//DFS function
void dfs(int vertex){
    time_in[vertex]=crt_time++; // adding in time in array v1[vertex]
    
    vis[vertex] = true; // maintaining visited array
    for (auto child:v1[vertex])
    {
        // if child is visited then continue else again use dfs on child
        if(vis[child]) continue;
        dfs(child);
    }
    time_out[vertex] = crt_time++;
    return;
}

// for a tree edge (u,v)
// v will be descendant of u
bool is_tree_edge(int start,int end){
    return time_in[start]<time_in[end] && time_out[start]>time_out[end];
}

// driver code
int main(int argc, char const *argv[])
{
    int n,m; // input n = no of vertices and m = no of edges
    cin>>n>>m;
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int x,y; // x = start vertex , y = end vertex for an edge  
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x); // as graph is undirected
        edge e = {x,y};
        edges.push_back(e);
    }
    // taking root node as 0
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        cout<<"Vertex : "<<i<<" In time: "<<time_in[i]<<" Out time: "<<time_out[i]<<"\n";    
    }

    for (auto edge:edges)
    {
        if(is_tree_edge(edge.start,edge.end)){
            cout<<"("<<edge.start<<","<<edge.end<<")"<<" -> Is a Tree edge\n";
        }
        else{
            cout<<"("<<edge.start<<","<<edge.end<<")"<<" -> Is a Back edge\n";
        }
    }

    return 0;
}
