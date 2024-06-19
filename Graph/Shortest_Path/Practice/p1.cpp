#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> prii;
int INF = 1e9 + 10;
const int N = 1e5 + 7;
vector<prii> arg[N];
bool visited[N];
vector<int> dist(N, INF);

void bfs(int src)
{
    priority_queue<prii, vector<prii>, greater<prii>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while(!pq.empty())
    {
        auto u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(auto pr:arg[u])
        {
            int v = pr.second;
            int w = pr.first;

            if (visited[v])
                continue;
            if(dist[v]>dist[u]+w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arg[u].push_back({w, v});
        arg[v].push_back({w, u});
    }
    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << dist[d];

    return 0;
}

