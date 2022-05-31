#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
int ordered[N];
int in_degree[N]; // answer

bool kahn_bfs(int n){
    queue<int> q1;  // maintain a queue 
    for (int i = 0; i < n; i++)
        if(in_degree[i]==0)
            q1.push(i); // add the nodes in answer which have indegree 0

    int index = 0;
    while (!q1.empty())
    {
        auto crt = q1.front();
        q1.pop();
        ordered[index++] = crt; // add the node in answer which have indegree 0 
        for(auto child:adj[crt]){
            in_degree[child] = in_degree[child]-1; // decrease the indegree of child by 1
            if(in_degree[child]==0){
                q1.push(child); // if indegree[child] = 0 then enqueue the child as it is independent 
            }                   // of dependencies 
        }
    }
    if(index != n){
        return false;   //graph contains cycles
    }
    return true; // graph is DAG and topological ordering is done 
}

// driver code
int main()
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++){
        int a,b;
        cin>>a>>b; // taking input start,end for e edges 
        adj[a].push_back(b); // make adj list of directed graph 
        in_degree[b]++;
    }
    bool ordering_done = kahn_bfs(v);
    if(!ordering_done){
        cout<<"Graph is not a DAG or cycle present in this directed graph";
    }
    else{
        cout<<"Topological Ordered Nodes: ";
        for(int i=0;i<v;i++){
            cout<<ordered[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}


