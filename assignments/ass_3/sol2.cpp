#include <iostream>
#include <vector>
#include <stack>

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
    int n,m,k;
    cin>>n>>m>>k;
    dsu ans(n);
    int a,b;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
    }
    stack<vector<int> > qurs;
    for (int i = 0; i < k; i++)
    {
        string p;
        cin>>p>>a>>b;
        a--,b--;
        if(p=="ask"){
            qurs.push({1,a,b});
        }
        else{
            qurs.push({0,a,b});
        }
    }
    vector<string> answer;
    while(!qurs.empty()){
        auto x = qurs.top();
        qurs.pop();
        if(x[0]){
            answer.push_back((ans.find_parent(x[1])==ans.find_parent(x[2]))?"YES\n":"NO\n");
        }
        else{
            ans.union_sets(x[1],x[2]);
        }
    }
    for(auto it=answer.rbegin();it!=answer.rend();it++){
        cout<<*it;
    }
}
