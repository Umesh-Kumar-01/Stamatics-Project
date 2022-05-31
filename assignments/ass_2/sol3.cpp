#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int N = 1e5+10;
vector<int> adj[N],rev[N];
int vis[N];


// using kosaraju algorithm 
stack<int> mystack;

void dfs1(int v){
    vis[v] = true;
    for(auto child:adj[v]){
        if(vis[child]) continue;
        dfs1(child);
    }
    mystack.push(v);
}

void dfs2(int v,int count){
    vis[v] = count;
    for(auto child:rev[v]){
        if(vis[child]) continue;
        dfs2(child,count);
    }
}

int findSCCs(int n){
    for(int i = 1; i <=n; i++){
        if(!vis[i])
            dfs1(i);
    }

    for (int i =1; i <= n; i++)
    {
        vis[i] = false;
    }
    
    // cout << "Strongly Connected Components are:\n"
    int counter = 1;
    while(!mystack.empty()){
        int crt = mystack.top();
        mystack.pop();
        if(vis[crt]) continue;
        dfs2(crt,counter);
        counter++;
    }
    return counter-1;
}
// driver code
int main()
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a); // making reversed graph 
    }
    cout<<findSCCs(v)<<endl;
    for (int i = 1; i <= v; i++)
    {
        cout<<vis[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
