#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> v[N];
bool visited[N];

void bfs(int n)
{
    queue< int > q;
    q.push(n);
    visited[n] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // cout << front << " ";

        for(int j:v[front])
        {
            if(visited[j])
                continue;
            q.push(j);
            visited[j] = true;
        }
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
        if(visited[i])continue;
        bfs(i);
        cc++;
    }
    cout << cc;

    return 0;
}