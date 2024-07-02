#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
const int N = 1e5 + 7;

vector<pr> adj[N];
int dist[N];
bool vis[N];

void optimized_dijstra(int n)
{
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    dist[n] = 0;
    pq.push({0, n});

    while(!pq.empty())
    {
    // cout << "called" << endl;
        int front = pq.top().second;
        pq.pop();

        if(vis[front]==1)
            continue;
        vis[front] = true;

        for(pr child:adj[front])
        {
            int weight = child.first;
            int node = child.second;

            if(dist[front]+weight<dist[node])
            {
                dist[node] = dist[front] + weight;
                pq.push({dist[node], node});
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
    optimized_dijstra(1);
    for (int i = 1; i <= nodes; i++)
    {
        cout << "node " << i << " len " << dist[i] << endl;
    }

    return 0;
}