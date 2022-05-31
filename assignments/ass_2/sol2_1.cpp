/*
Finding Sortest path 
in the DAG using Topological Sorting 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>


using namespace std;
const int N = 1e6+10;
vector<pair<int,int> > adj[N];
int ordered[N];
int in_degree[N];

// topological sorting 

// using kahn's algorithm 
bool kahn_bfs(int n){
    queue<int> q1;
    for (int i = 1; i <= n; i++)
        if(in_degree[i]==0){
            q1.push(i);
        }
    int index = 0;
    while(!q1.empty()){
        int crt = q1.front();
        q1.pop();
        ordered[index++]=crt;
        for(auto y: adj[crt]){
            int x = y.first;
            in_degree[x] -=1;
            if(in_degree[x]==0){
                q1.push(x);
            }
        }
    }
    if(index!=n){
        return false;
    }
    return true;
}

// shortest path from u to v
/*
    f(u,v) = min(f(y,v)+wt(x,y)) : y belongs to adj[u]
*/

vector<int> dis(N,INT_MAX);
void shortest_path(int end,int n){
    int index = n-1;
    while(index>=0){
        if(ordered[index]==end) break;
        index--;
    }
    dis[ordered[index--]]=0;
    while(index>=0){
        for(auto child:adj[ordered[index]]){
            if(dis[child.first]==INT_MAX) continue;
            dis[ordered[index]] = min(dis[child.first]+child.second,dis[ordered[index]]);
        }
        index--;
    }
    return; 
}

void dfs_print(int index,int v){
    cout<<index<<" ";
    if(index==v) return;
    for(auto child:adj[index]){
        if(dis[child.first]+child.second == dis[index]){
            dfs_print(child.first,v);
            break;
        }
    }
}
// return 1 if path exists else return zero
bool print_shortest_path(int u,int v,int n){
    shortest_path(v,n);
    if(dis[u]==INT_MAX) return false;
    cout<<dis[u]+1<<"\n"; // for cses question 
    dfs_print(u,v);
    return true;
}
// driver's code

int main(int argc, char const *argv[])
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++)
    {
        // taking vertices from 1,2 ... v 
        int a,b,c=1;
        // cin>>a>>b>>c; // for weighted graph
        cin>>a>>b; // for unweighted graph
        adj[a].push_back({b,c});
        in_degree[b]++;
    }

    // topological ordering required 
    if(!kahn_bfs(v)) cout<<"IMPOSSIBLE\n";
    if(!print_shortest_path(1,v,v)) cout<<"IMPOSSIBLE\n";
    return 0;
}