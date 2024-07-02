#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
bool vis[N];
int parent[N];

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    parent[n] = -1;
    vis[n] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(int child:adj[front])
        {
            if(vis[child])
                continue;

            vis[child] = true;
            parent[child] = front;
            q.push(child);
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    while(edges--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= nodes; i++)
    {
        cout << "node" << i << " parent" << parent[i] << endl;
    }
    int s;
    cin >> s;
    if(parent[s])
    {
        int temp = s;
        vector<int> x;
        x.push_back(temp);
        for (int i = 1; i <= nodes; i++)
        {
            temp = parent[temp];
            if(temp>0)
                x.push_back(temp);
        }
        reverse(x.begin(), x.end());
        cout << "shortest path of " << s << " is: ";
        for (int i : x)
            cout << i << " ";
    }
    else
        cout << "no path" << endl;

        return 0;
}