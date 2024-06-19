#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> prii;
int INF = 1e9 + 10;
const int N = 1e5 + 7;
vector<prii> arg[N];
vector<int> dist(N, INF);
int parent[N];

void bfs(int src)
{
    priority_queue<prii, vector<prii>, greater<prii>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});
    parent[src] = -1;

    while(!pq.empty())
    {
        auto u = pq.top().second;
        pq.pop();

        for(auto pr:arg[u])
        {
            int v = pr.second;
            int w = pr.first;

            if(dist[v]>dist[u]+w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
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
    }
    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << dist[d] << endl;

    for (int i = 1; i <= nodes; i++)
    {
        cout << "node " << i << ": parent: " << parent[i] << endl;
    }
    vector<int> path;
    int curr = d;
    while(curr!=-1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    
    for(int i:path)
    {
        cout << i << " <-";
    }

    return 0;
}

