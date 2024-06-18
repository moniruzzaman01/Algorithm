#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> v[N];
bool visited[N];

void bfs(int n)
{
    vector<int> temp;
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        temp.push_back(front);

        for(int child:v[front])
        {
            if(visited[child])
                continue;
            q.push(child);
            visited[child] = true;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        cout << temp[i] << " ";
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 1; i <= nodes; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
    return 0;
}