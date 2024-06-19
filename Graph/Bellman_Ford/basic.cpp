#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> prii;
const int N = 1e3 + 5;
vector<prii> adj[N];

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

        return 0;
}