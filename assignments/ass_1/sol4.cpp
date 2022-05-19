#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5+10;
vector<int> v1[N];
bool vis[N];

bool dfs(int vertex,int parent){
    vis[vertex] = true;
    bool w = false;
    for (auto child:v1[vertex])
    {
        if(vis[child] && child!=parent) return true;
        if(vis[child]) continue;
        w |= dfs(child,vertex);
    }
    return w;
}
int main(int argc, char const *argv[])
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++)
    {
        int x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    for (int i = 0; i < v; i++)
    {
        if(vis[i]) continue;
        if(dfs(i,-1)){
            cout<<"Cycle present\n";
            return 0;
        }
    }
    cout<<"Cycle Not Present\n";
    return 0;
}
