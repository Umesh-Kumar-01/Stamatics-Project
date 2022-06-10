#include <iostream>
#include <vector>

using namespace std;

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