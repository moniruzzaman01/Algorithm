#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int u, v, w;
        Edge(int a, int b, int c)
        {
            this->u = a;
            this->v = b;
            this->w = c;
        }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> adj;
    int dist[n + 1];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge ed(a, b, c);
        adj.push_back(ed);
    }
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < adj.size(); j++)
        {
            Edge ed = adj[j];
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            if(dist[u]+w<dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "dist " << i << " - " << dist[i] << endl;
    }

        return 0;
}