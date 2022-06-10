#include <iostream>
#include <vector>

using namespace std;

//Writing code with reference to this problem: https://cses.fi/problemset/task/1648 
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
};

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    fenwicktree answer(n);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        answer.add(i,a);
    }
    // answer.print_tree();
    while(m--){
        int w,a,b;
        cin>>w>>a>>b;
        if(w==1){
            long long int w = answer.sum(a,a);
            answer.add(a,b-w);
        }
        else if(w==2){
            cout<<answer.sum(a,b)<<"\n";
        }
    }
    return 0;
}