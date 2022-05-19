#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5+10;

// using marker as if edge (u,v) is bridge then adj[u].second = 1 
// else it is zero 
// 1 means edge is deleted else edge is present
vector<pair<int,int> > adj[N];

bool visited[N];
int tim_in[N]; // discovery or in time
int low[N];

int timer;

vector<pair<int,int> > brd;
void delete_bridge(int v,int u){
    for (int i = 0; i < adj[v].size(); i++){
        if(adj[v][i].first==u){
            adj[v][i].second=1;
        }
    }
    for (int i = 0; i < adj[u].size(); i++)
    {
        if(adj[u][i].first==v){
            adj[u][i].second=1;
        }
    }
    brd.push_back({v,u});
    return;
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tim_in[v] = low[v] = timer;
    timer++;
    for (auto child : adj[v]){
        if (child.first == p) continue;
        if (visited[child.first]) {
            low[v] = min(low[v], tim_in[child.first]);
        } 
        else {
            dfs(child.first, v);
            low[v] = min(low[v], low[child.first]);
            if (low[child.first] > tim_in[v])
                delete_bridge(v, child.first);
        }
    }
}

int main(int argc, char const *argv[])
{
    timer =0;
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,0});
        adj[y].push_back({x,0});
    }
    for (int i = 0; i < v; i++)
    {
        if(!visited[i]){
            dfs(i);
        }
    }
    // Graph after removing bridges
    for (int i = 0; i < v; i++)
    {
        cout<<i<<" -> ";
        for(auto child:adj[i]){
            if(child.second==1) continue;
            cout<<child.first<<" ";
        }
        cout<<"\n";
    }

    // bridges

    for(auto x:brd){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    return 0;
}
