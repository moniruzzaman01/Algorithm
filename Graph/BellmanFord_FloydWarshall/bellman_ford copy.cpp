#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> prii;
int INF = 1e9 + 10;
const int N = 1e5 + 7;
vector<prii> g[N];
vector<int> dist(N, INF);
// int dist[N];
int nodes, edges;

void bellman_ford(int s)
{
    dist[s]=0;

    for (int i = 1; i < nodes; i++)
    {
        for (int u = 1; u <= nodes; u++)
        {
            for (prii pr : g[u])
            {
                int v = pr.first;
                int w = pr.second;

                if (dist[u] != INF && dist[v] > dist[u] + w)
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
    for (int i = 1; i <= edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }

    bellman_ford(1);

    for (int i = 1; i <= nodes; i++)
    {
        cout << "distance of " << i <<": " << dist[i] << endl;
    }
    // for (int i = 1; i <= nodes; i++)
    // {
    //     for(prii pr:g[i])
    //     {
    //         int v = pr.second;
    //         int w = pr.first;

    //         cout << "u" << i << " v" << v << " w" << w << endl;
    //     }
    // }

        return 0;
}