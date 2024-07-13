#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7 + 10;
int main()
{
    int n, e;
    cin >> n >> e;
    int dis[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i==j)
            {
                dis[i][j] = 0;
                continue;
            }
            dis[i][j] = inf;
        }
    }
    while(e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dis[i][j]==inf)
            {
                cout << "X ";
                continue;
            }
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

        return 0;
}