#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> v[N];
bool visited[N];

void dfs(int p)
{
    // 1: take actions on parent after entering parent
    visited[p] = true;
    cout << "visited node: " << p << endl;
    for (int i : v[p])
    {
        // 2: take actions on neighbour/child before entering a new neighbour/child node
        if(visited[i]==true)
            continue;
        dfs(i);
        // 3: take actions on neighbour/child after exiting a neighbour/child node
    }
    // 4: take actions on parent before exiting parent
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    // for (int i = 1; i <= nodes; i++)
    // {
    //     cout << "node" << i << ": ";
    //     for (int j : v[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    dfs(1);

    return 0;
}