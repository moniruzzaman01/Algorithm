#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> v[N];
bool visited[N];

bool bfs(int n)
{
    queue< int > q;
    q.push(n);
    visited[n] = true;
    int parent = n;
    bool flag = false;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // cout << front << " ";

        for(int j:v[front])
        {
            if(j == parent)
                continue;
            if(visited[j])
            {
                flag = true;
                break;
            }
            q.push(j);
            visited[j] = true;
        }
        parent = front;
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
    bool isCyclic = bfs(1);
    if(isCyclic)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}