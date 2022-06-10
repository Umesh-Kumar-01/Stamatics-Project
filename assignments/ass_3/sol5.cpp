#include <iostream>
#include <vector>

using namespace std;

//Writing code with reference to this problem: https://cses.fi/problemset/task/1651 
class fenwicktree
{
private:
    vector<long long int> tree;
    int n;
public:
    fenwicktree(int n){
        this->n = n;
        tree.resize(n+1,0);
    }

    fenwicktree(vector<int> & v):fenwicktree(v.size()){
        for (size_t i = 1; i <= n; i++)
        {
            add(i,v[i-1]);
        }
    }
    void print_tree(){
        for (size_t i = 0; i < tree.size(); i++)
        {
            cout<<tree[i]<<" ";
        }
        cout<<"\n";
    }
    long long int sum(int idx){
        long long int ans =0;
        while(idx>0){
            ans += tree[idx];
            idx -= idx&(-idx);
        }
        return ans;
    }

    long long int sum(int l,int r){
        long long int w = sum(r);
        long long int e = sum(l-1);
        return w-e;
    }

    void add(int i,long long int w){
        for (; i <= n; i+= i&(-i))
        {
            tree[i] += w;
        }
    }

    void add_range(int l,int r,long long int val){
        add(l,val);
        add(r+1,-val);
    }

};

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    fenwicktree answer(n);
    vector<int> vec(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        cin>>vec[i];
    }
    // answer.print_tree();
    while(m--){
        int w;
        cin>>w;
        if(w==1){
            int a,b,c;
            cin>>a>>b>>c;
            answer.add_range(a,b,c);
        }
        else if(w==2){
            int a;
            cin>>a;
            cout<<answer.sum(a)+vec[a]<<"\n";
        }
    }
    return 0;
}