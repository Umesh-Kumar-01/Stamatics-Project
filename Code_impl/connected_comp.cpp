#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5+10;
vector<int> v1[N];
bool vis[N];

vector<vector<int> > connected_components;
void dfs(int vertex,vector<int> &temp){
    vis[vertex] = true;
    temp.push_back(vertex);
    for (auto child:v1[vertex])
    {
        if(vis[child]) continue;
        dfs(child,temp);
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
    int conected_comp =0;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        if(vis[i]) continue;
        dfs(i,temp);
        conected_comp++;
        connected_components.push_back(temp);
        temp.clear();
    }
    return 0;
}
