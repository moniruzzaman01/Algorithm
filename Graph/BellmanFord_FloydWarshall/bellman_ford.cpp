#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> prii;
int INF = 1e9 + 10;
const int N = 1e5 + 7;
vector<prii> adj[N];
vector<int> dist(N, INF);
int nodes, edges;

void bellman_ford(int s)
{
    dist[s] = 0;

    for (int i = 1; i < nodes; i++)//n-1 time loop
    {
        for (int u = 1; u <= nodes; u++)//to loop all nodes
        {
            for(prii pr:adj[u])
            {
                int v = pr.second;
                int w = pr.first;
                if(dist[u]!=INF && dist[v]>dist[u]+w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;
    while(edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    bellman_ford(1);

    for (int i = 1; i <= nodes; i++)
    {
        cout << "distance of " << i << ": " << dist[i] << endl;
    }

        return 0;
}