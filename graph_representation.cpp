#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    /* *********** matrix representation ***************** */  
    int v,e;;
    cin>>v>>e;
    vector<vector<int> > graph_mat(v,vector<int> (v,0));
    for (int i = 0; i < e; i++)
    {
        // let say edge E = (start_vertex,last_vertex,weight);
        int start_v,last_v,weight;
        cin>>start_v>>last_v>>weight;
        // vertices starts from 0 here
        graph_mat[start_v][last_v]=weight;
    }
    //print matrix
    cout<<"Adjacency Matrix of input graph is:\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout<<graph_mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
