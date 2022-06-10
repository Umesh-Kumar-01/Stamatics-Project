#include <iostream>
#include <vector>

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
    // using above dsu data structure trying to solve this question:
    // https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
    int n,m; 
    cin>>n>>m;
    
    // initialize data structure 
    dsu ans(n);
    while(m--){
        string w;
        int a,b;
        cin>>w>>a>>b;
        a--,b--;// as data structure defined on zero -index so subtracting 1 from a and b to start them from 0
        if(w=="union"){
            ans.union_sets(a,b);
        }
        else{
            int w = ans.find_parent(a);
            int v = ans.find_parent(b);
            bool k = (w==v);
            cout<<((k)?"YES\n":"NO\n");
        }
    }
    return 0;
}
