#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> v[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;
    level[n] = 0;
    parent[n] = -1;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // cout << front << " ";

        for(int i:v[front])
        {
            if(visited[i])
                continue;
            q.push(i);
            visited[i] = true;
            level[i] = level[front] + 1;
            parent[i] = front;
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
    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << "distance: " << level[d] << endl;

    // for (int i = 1; i <= nodes; i++)
    // {
    //     cout << "node " << i << ": " << parent[i] << endl;
    // }

    vector<int> path;
    int curr = d;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
    cout << "path: ";
    for (int i : path)
    {
        cout << i << " ";
    }

        return 0;
}