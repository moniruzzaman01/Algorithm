#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> v[N];
bool visited[N];

void dfs(int n)
{
    visited[n] = true;
    for (int i : v[n])
    {
        if(visited[i]) continue;
        dfs(i);
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
    int cc = 0;
    for (int i = 1; i <= nodes; i++)
    {
        if(visited[i]) continue;
        dfs(i);
        cc++;
    }
    cout << "number of components: " << cc;

        return 0;
}