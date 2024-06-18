#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int height[N];

void dfs(int parent)
{
    visited[parent] = true;
    for (int child : adj[parent])
    {
        if(visited[child]==true)
            continue;
        dfs(child);
        height[parent] = max(height[parent], height[child] + 1);
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i<=nodes; i++)
    {
        cout << "height of node: " << i << " :" << height[i] << endl;
    }
    for (int i = 1; i <= nodes; i++)
    {
        cout << "nodes " << i << ": ";
        for(int j:adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

        return 0;
}