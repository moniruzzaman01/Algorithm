#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> prii;
const int N = 1e5 + 7;
vector<string> g;
int nodes, edges;
vector<prii> dist = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[N][N];
bool isValid(int i, int j)
{
    return (i >= 0 && i < nodes && j >= 0 && j < edges);
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;

    for(auto pr:dist)
    {
        int ni = si + pr.first;
        int nj = sj + pr.second;
        if(isValid(ni,nj) && !visited[ni][nj] && g[ni][nj]!='x')
        {
            visited[ni][nj] = true;
            dfs(ni, nj);
        }
    }
}

void bfs(int si, int sj)
{
    queue<prii> q;
    q.push({si, sj});
    visited[si][sj] = true;

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
    dfs(si, sj);
    if(visited[di][dj])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}