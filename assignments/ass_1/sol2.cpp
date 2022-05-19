#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
bool vis[N];                     // define visited array
vector<int> adj[N];              // using adjacency list rep

vector<int> distance_vec(N, -1); 
/* deafult value of distance=-1 so that unreachable 
feasible vertices have distance -1
*/

// Implanting BFS
void bfs(int vertex)
{
    queue<int> q;   
    q.push(vertex);
    vis[vertex] = 1;
    distance_vec[vertex] = 0;

    while (!q.empty())
    {
        int crt_node = q.front();
        q.pop();
        // cout<<crt_node<<" ";
        for (int child : adj[vertex])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                distance_vec[child] = distance_vec[crt_node] + 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //taking root as 0
    bfs(0);

    for (int i = 0; i < v; i++)
    {
        // printing vertices and repective distances with root vertex
        cout << "Node " << i << " has distance_vec " << distance_vec[i] << "\n";
    }
    return 0;
}
