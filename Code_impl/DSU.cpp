#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1e5+10;
vector<int> parent;

void intilize_dsu(int n){
    parent.resize(n,-1); // intially all nodes are disjoint with each other 
    // here - represent that it is a root node and 1 represent size of set
}

int find_parent(int w){
    /* // naive approach 
    
    while(parent[w]>=0){
        w = parent[w];
    }
    return w // TC: O(N) 
    */
    if(parent[w]<0) return w;
    return parent[w] = find_parent(parent[w]); // path compression optimization 
    // TC: O(log N) average
}

void union_sets(int a,int b){
    a = find_parent(a);
    b = find_parent(b);
    // union by size/ rank 
    if(a!=b){
        if(parent[b]<parent[a]){
            swap(a,b);
        }
        parent[a] += parent[b];
        parent[b]=a;
    }
}
