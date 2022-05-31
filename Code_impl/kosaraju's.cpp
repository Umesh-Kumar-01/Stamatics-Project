#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
int vis[N];
vector<int> rev[N];
stack<int> mystack;

void dfs1(int w){
    vis[w] =true;
    for(auto child : adj[w]){
        if(vis[child]) continue;
        dfs1(child);
    }
    mystack.push(w);
}

void reverse_list(int n){
    for (int i = 0; i < n; i++)
    {
        for(auto child:adj[i]){
            rev[child].push_back(i);
        }
    }
    return;
}

void dfs2(int w,int count){
    // cout<<"i ";
    vis[w] = count;
    for(auto child:adj[w]){
        if(vis[child]) continue;
        dfs2(child,count);
    }
    return;
}

int findSCCs(int n){
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs1(i);
    }

    for (int i = 0; i < n; i++)
        vis[i] = false;
    
    // cout<<"Strongly Connected Componnts are:\n";
    int counter =1;
    while (!mystack.empty())
    {
        int crt = mystack.top();
        mystack.pop();
        if(vis[crt]) continue;
        dfs2(crt,counter);
        counter++;
        // cout<<"\n";
    }
    return counter-1;
}

int main()
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cout<<findSCCs(v); // cout no of SCCs
    // for(auto i = 1;i<=v;i++){
    //     cout << vis[i]<<" ";
    // }
    return 0;
}
