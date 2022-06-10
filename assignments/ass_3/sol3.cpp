#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class dsu
{
private:
    vector<int> parent;
public:
    dsu(int n);
    int find_parent(int);
    void union_sets(int,int);
};

dsu::dsu(int n)
{
    parent.resize(n,-1);
    // -1 represent root node
}

int dsu::find_parent(int n){
    if(parent[n]<0) return n;
    return parent[n]=find_parent(parent[n]);
}

void dsu::union_sets(int a,int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a!=b){
        if(parent[b]<parent[a]) swap(a,b);
        parent[a] += parent[b];
        parent[b]=a;
    }
    return;
}


//driver code
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    dsu ans(n);
    vector<pair<int,pair<int,int> > >edges;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());

    int min_cost =0;
    for(auto x:edges){
        int wt = x.first;
        int u = x.second.first;
        int v = x.second.second;
        u--,v--;
        if(ans.find_parent(u)==ans.find_parent(v)) continue;
        ans.union_sets(u,v);
        min_cost += x.first;
    }
    cout<<min_cost<<"\n";
}
