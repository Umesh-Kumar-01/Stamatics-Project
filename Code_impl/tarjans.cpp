#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
bool dis_time[N];
bool low_time[N];
bool in_stack[N];
stack<int> mystack;

vector<vector<int> > SSCs;
int timer =0;
void dfs(int v){
    dis_time[v] = low_time[v]=timer++;
    mystack.push(v);
    in_stack[v] = true;
    
    for(auto child:adj[v]){
        if(dis_time[v]==-1){
            dfs(child);
            low_time[child]=min(low_time[child],low_time[v]);
        }
        else if(in_stack[child]){
            low_time[v] = min(low_time[v],dis_time[child]);
        }
    }
    if(low_time[v]==dis_time[v]){
        vector<int> w;
        while(mystack.top()!=v){
            w.push_back(mystack.top());
            in_stack[mystack.top()]=false;
            mystack.pop();
        }
        w.push_back(mystack.top());
        in_stack[mystack.top()]=false;
        mystack.pop();
        SSCs.push_back(w);
    }
}

void findSCC_trajan(int n){
    for (int i = 0; i < n; i++)
    {
        dis_time[i] =1;
        low_time[i] =1;
    }
    for (int i = 0; i < n; i++)
    {
        if(dis_time[i]==-1){
            dfs(i);
        }
    }
    
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
    }
    findSCC_trajan(v);

    // printing SSCs
    for(auto x:SSCs){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}