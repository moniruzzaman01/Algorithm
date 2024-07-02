#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
const int N = 1e5 + 7;

vector<pr> adj[N];
int dist[N];

void naive_dijstra(int n)
{
    queue<int> q;
    dist[n] = 0;
    q.push(n);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(pr child:adj[front])
        {
            int weight = child.first;
            int node = child.second;

            if(dist[front]+weight<dist[node])
            {
                dist[node] = dist[front] + weight;
                q.push(node);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    while(edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    for (int i = 1; i <= nodes; i++)
    {
        dist[i] = INT_MAX;
    }
    naive_dijstra(1);
    for (int i = 1; i <= nodes; i++)
    {
        cout << "node " << i << " len " << dist[i] << endl;
    }

    return 0;
}