#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> prii;

const int N = 1e3 + 7;
const int INF = 1e9 + 10;

vector< prii > vec[N];
vector<int> visited(N);
vector<int> dist(N, INF);

void dijkstra(int src)
{
    priority_queue<prii, vector<prii>, greater<prii>> pq;
    dist[src] = 0;
    pq.push(make_pair(dist[src], src));

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(prii item:vec[u])
        {
            int v = item.first;
            int w = item.second;

            if(visited[v])continue;

            if(dist[v]>dist[u]+w){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
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
        vec[u].push_back(make_pair(v, w));
        vec[v].push_back(make_pair(u, w));
    }
    // for (int i = 1; i < nodes; i++)
    // {
    //     cout << "node " << i << ": ";
    //     for (prii j : vec[i])
    //     {
    //         cout << "{" << j.first << " " << j.second << "}" << " ";
    //     }
    //     cout << endl;
    // }
    dijkstra(1);
    for (int i = 1; i <= nodes; i++)
    {
        cout << "node " << i << ": " << dist[i] << " " << endl;
    }

        return 0;
}