// CSES Giant Pizza Problem 2SAT Problem 
/*
- exclude and + include
lets take an example 
3 5
+ 1 + 2
- 1 + 3
+ 4 - 2

=> here 2SAT expression will be
(1 or 2) and (not 1 or 3) and (4 or not 2)

then use topological sorting to solve it
*/



#include <iostream>
#include <vector>
#include <stack> 

using namespace std;
const int N = 1e6+10;
vector<int> adj[N],rev[N];
int vis[N];
bool assing[N];

// using kosaraju algorithm 
stack<int> mystack;

void dfs1(int vertex){
    vis[vertex]=true;
    for(auto child:adj[vertex]){
        if(vis[child]) continue;
        dfs1(child);
    }
    mystack.push(vertex);
}

void dfs2(int vertex,int cnt){
    vis[vertex] = cnt;
    for(auto child:rev[vertex]){
        if(vis[child]) continue;
        dfs2(child,cnt);
    }
}

int SAT2(int n){
    for (int i = 1; i <= n; i++){
        if(vis[i]) continue;
        dfs1(i);
    }

    for (int i = 1; i <=n; i++){
        vis[i] = false;
    }
    
    int counter =1;
    while(!mystack.empty()){
        int crt = mystack.top();
        mystack.pop();
        if(vis[crt]) continue;
        dfs2(crt,counter);
        counter++;
    }
    int w = n/2;
    for (int i = 1; i <= w; i++)
    {
        if(vis[i]==vis[w+i]) return false;
        assing[i] = vis[i]>vis[w+i];
    }
    return true;
}

int get_index(int a,bool sign_a,int n){
    if(!sign_a) return a+n;
    return a;
}
void add_edge(int a,int b,bool sign_a,bool sign_b,int n){
    int a1 = get_index(a,!sign_a,n);
    int a2 = get_index(b,sign_b,n);
    int b1 = get_index(b,!sign_b,n);
    int b2 = get_index(a,sign_a,n);
    // cout<<a1<<a2<<b1<<b2<<"\n";
    adj[a1].push_back(a2);
    adj[b1].push_back(b2);

    // filling reversed graph
    rev[a2].push_back(a1);
    rev[b2].push_back(b1);
    return;
}

int main()
{
    int e,v;
    cin>>e>>v;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        char s_a,s_b;
        cin>>s_a>>a>>s_b>>b;
        // cout<<s_a<<"|"<<a<<"|"<<s_b<<"|"<<b<<"\n";
        bool w = s_a=='+';
        bool e = s_b=='+';
        add_edge(a,b,w,e,v);
    }
    if(SAT2(2*v)){
        for(int i =1;i<=v;i++){
            if(assing[i]) cout<<"+ ";
            else cout<<"- ";
        }
        cout<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
