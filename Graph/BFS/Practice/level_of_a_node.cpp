#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> v[N];
bool visited[N];

void bfs(int n,int k)
{
    queue< pair<int,int> > q;
    q.push(make_pair(n, 0));
    visited[n] = true;

    while(!q.empty())
    {
        pair<int,int> front = q.front();
        q.pop();

        if(front.first==k)
        {
            cout << "Level of " << front.first << " = " << front.second << endl;
            break;
        }

        for(int j:v[front.first])
        {
            if(visited[j])
                continue;
            q.push(make_pair(j,front.second+1));
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
    int k;
    cin >> k;
    bfs(1,k);

    return 0;
}