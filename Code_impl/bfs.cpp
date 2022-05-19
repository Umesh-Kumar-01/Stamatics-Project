#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5+10;
bool vis[N];
vector<int> adj[N];
int level[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] =1;

    while (!q.empty())
    {
        int crt_node = q.front();
        q.pop();
        // cout<<crt_node<<" ";
        for(int child:adj[source]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                level[child]=level[crt_node]+1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1);
    // for (int i = 0; i <v; i++)
    // {
    //     cout<<"Node "<<i<<" has level "<<level[i]<<"\n";
    // }
    return 0;
}

