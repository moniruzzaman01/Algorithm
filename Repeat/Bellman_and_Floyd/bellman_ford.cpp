#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<pair<int, int>> adj[N];
int dist[N];
void bellman_ford(int src, int n)
{
    dist[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int u = 0; u <= n; u++)
        {
            for(pair<int,int> vw:adj[u])
            {
                int v = vw.second;
                int w = vw.first;
                if(dist[u]+w<dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX;
    bellman_ford(1, n);

    for (int i = 1; i <= n;i++)
    {
        cout << "dist " << i << " - " << dist[i] << endl;
    }

        return 0;
}