#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5+10;
bool vis[N];
vector<int> v1[N];
void dfs(int vertex){
    vis[vertex] = true;
    // cout<<vertex<<" ";
    for (auto child:v1[vertex])
    {
        if(vis[child]) continue;
        dfs(child);
    }
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    dfs(2);
    return 0;
}
