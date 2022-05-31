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

/*
    # paths (u,v)
    f(x) = sum(f(y,v)) : y belongs to adj[u]
*/

int no_of_path(int u,int v,int n){
    vector<int> dp(n+1,0);
    if(!kahn_bfs(n)) return 0;
    int index = n-1;
    while(index>=0){
        if(ordered[index]==v) break;
        index--;
    }
    dp[ordered[index--]]=1;
    while(index>=0){
        for(auto x:adj[ordered[index]]){
            dp[ordered[index]] += dp[x.first];
            // dp[ordered[index]] += dp[x];   // for unweighted graph;
        }
        if(ordered[index]==u) break;
        index--;
    }
    // for(int i=0;i<v;i++){
    //     cout<<dp[i]<<"\n";
    // }
    return dp[ordered[index]];
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
    }
    // topological ordering required 
    cout<<no_of_path(1,v,v)<<"\n";
    return 0;
}