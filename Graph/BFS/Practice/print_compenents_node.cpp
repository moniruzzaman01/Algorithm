#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> v[N];
bool visited[N];
vector< pair<int, vector<int> > > v2;

void bfs(int n, int cc)
{
    queue< int > q;
    q.push(n);
    visited[n] = true;
    vector<int> v3;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        v3.push_back(front);
        // cout << front << " ";

        for(int j:v[front])
        {
            if(visited[j])
                continue;
            q.push(j);
            visited[j] = true;
        }
    }
    v2.push_back(make_pair(cc, v3));
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
        bfs(i,cc);
        cc++;
    }
    cout << cc << endl;
    for (auto i : v2)
    {
        cout << "Component " << i.first+1 << " : ";
        for (auto j : i.second)
            cout << j << " ";
        cout << endl;
    }

        return 0;
}