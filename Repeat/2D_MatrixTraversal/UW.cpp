#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
const int N = 1e3 + 5;
bool vis[N][N];
int dis[N][N];
vector<pr> route = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValid(int si, int sj, int n, int m)
{
    return (si >= 0 && sj >= 0 && si < n && sj < m);
}
void bfs(int si, int sj, int n, int m)
{
    queue<pr> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty())
    {
        pr front = q.front();
        int i = front.first;
        int j = front.second;
        q.pop();

        for(pr rt:route)
        {
            int newi = i + rt.first;
            int newj = j + rt.second;
            if(isValid(newi,newj,n,m) && !vis[newi][newj])
            {
                vis[newi][newj] = true;
                dis[newi][newj] = dis[i][j] + 1;
                q.push({newi, newj});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    char mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    bfs(si, sj, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "dist of " << i << "," << j << " - " << dis[i][j] << endl;
        }
    }

    return 0;
}