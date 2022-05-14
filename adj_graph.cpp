#include<iostream>
#include<vector>

using namespace std;

struct edge{
    int start, end, weight;
};
class adj_graph
{
private:
    vector<vector<pair<int,int> > > adj_list;
public:
    adj_graph(const vector<edge> &v1,int vertices);
    void print_graph();
    void add_edge(edge &e);
};

adj_graph::adj_graph(const vector<edge> &v1,int vertices)
{
    adj_list.resize(vertices);
    for(auto it = v1.begin();it!=v1.end();it++){
        adj_list[it->start].push_back({it->end,it->weight});
    }
}

void adj_graph::print_graph(){
    int i=0;
    for(auto x:adj_list){
        cout<<i<<" ";
        int flag =1;
        for(auto w:x){
            if(flag){
                cout<<"("<<w.first<<", "<<w.second<<") ";
                flag=0;
                continue;
            }
            cout<<"--> ";
            cout<<"("<<w.first<<", "<<w.second<<") ";
        }    
        i++;
        cout<<"\n";
    }
}

void adj_graph ::add_edge(edge &e){
    adj_list[e.start].push_back({e.end,e.weight});
}

// driver code 
int main(int argc, char const *argv[])
{
    vector<edge> edges = {
        {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
    };
    // int vertices,edge_no;
    // cin>>vertices>>edge_no;
    // for (int i = 0; i < edge_no; i++)
    // {
    //     int s,e,w;
    //     cin>>s>>e>>w;
    //     edges.push_back({s,e,w});
    // }


    adj_graph grp(edges,6);
    grp.print_graph();
    return 0;
}
