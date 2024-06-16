#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> v[N];
bool visited[N];
int circle = 0;


bool dfs(int n, int p=-1)
{
    bool flag = false;
    visited[n] = true;
    for (int i : v[n])
    {
        if(i==p)continue;
        if (visited[i]) return true;
        flag = flag | dfs(i, n);
    }
    return flag;
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
    bool result = false;
    for (int i = 1; i <= nodes; i++)
    {
        if(visited[i])continue;
        result |= dfs(i);
    }
    if (result)
        cout << "cycle found!";
    else
        cout << "cycle not found!";

    return 0;
}