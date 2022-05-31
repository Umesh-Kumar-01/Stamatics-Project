#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
bool vis[N];
int ordered[N];

int dfs(int index,int at){
    vis[at]=true;
    for(auto child:adj[at]){
        if(vis[child]) continue;
        index = dfs(index,child);
    }
    ordered[index]=at;
    return index-1;
}

void top_sort(int n){
    int index = n-1;
    for (int i = 0; i < n; i++)
    {
        if(vis[i]==false){
            index = dfs(index,i);
        }
    }
}
//driver code 
int main(int argc, char const *argv[])
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++){
        int a,b;
        cin>>a>>b; // taking input start,end for e edges 
        adj[a].push_back(b); // make adj list of directed graph 
    }
    top_sort(v); // calling top_sort function 

    for(int i=0;i<v;i++){
        cout<<ordered[i]<<" "; //printing ordered values
    }
    return 0;
}
