#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> v[N];
bool visited[N];
int height[N];

void dfs(int parent)
{
    visited[parent] = true;
    for (int child : v[parent])
    {
        if(visited[child]==true)
            continue;
        dfs(child);
        height[parent] = max(height[child] + 1, height[parent]);
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
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    int n;
    cin >> n;
    cout << "height of " << n << " = " << height[n];

    return 0;
}