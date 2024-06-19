#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> prii;
const int N = 1e3 + 5;
vector<string> g;
int nodes, edges;
vector<prii> dist = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[N][N];
int level[N][N];
bool isValid(int i, int j)
{
    return (i >= 0 && i < nodes && j >= 0 && j < edges);
}

void bfs(int si, int sj)
{
    queue<prii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        prii front = q.front();
        q.pop();
        // cout << "called" << endl;

        for(prii pr:dist)
        {
            int ni = front.first + pr.first;
            int nj = front.second + pr.second;
            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'x')
            {
                visited[ni][nj] = true;
                q.push({ni, nj});
                level[ni][nj] = level[front.first][front.second] + 1;
            }
        }
    }
}

int main()
{
    int si, sj, di, dj;
    cin >> nodes >> edges;
    for (int i = 0; i < nodes; i++)
    {
        string s;
        cin >> s;
        g.push_back(s);
        for (int j = 0; j < edges; j++)
        {
            if(s[j]=='s')
            {
                si = i, sj = j;
            }
            if(s[j]=='e')
            {
                di = i, dj = j;
            }
        }
    }
    bfs(si, sj);
    if(visited[di][dj])
    {
        cout << level[di][dj];
    }
    else
    {
        cout << -1;
    }

    return 0;
}