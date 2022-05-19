#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5+10;
vector<int> v1[N];

int vis[N]; // storing id in visited array
/*
    instead of just storing true and false in visited array
    we will store a value(ID) > 0 when node is visited 
    and will increament ID when nodes left without visited
    after dfs call 
    and use dfs again 
*/

vector<vector<int> > connected_components; // store connected components;

int id =0; // maintaining ID variable values form 1 to k

//using dfs
void dfs(int vertex,vector<int> &temp){
    vis[vertex] = id;
    temp.push_back(vertex);
    for (auto child:v1[vertex])
    {
        if(vis[child]) continue;
        dfs(child,temp);
    }
}

//driver code 
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
        id++;
        connected_components.push_back(temp);
        temp.clear();
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"Vertex : "<<i<<" has ID: "<<vis[i]<<"\n";
    }
    return 0;
}
