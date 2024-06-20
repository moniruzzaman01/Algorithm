#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int INF = 1e9 + 10;
int dist[N][N];
int nodes, edges;

void print_matrix()
{
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            if(dist[i][j]==INF)
                cout << "X ";
            else
                cout << dist[i][j] << " ";
        }
        if(i!=nodes)
            cout << endl;
    }
}
void distance_initialize()
{
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            if(i!=j)
                dist[i][j] = INF;
        }
    }
}

int main()
{
    cin >> nodes >> edges;
    distance_initialize();
    while(edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        // dist[v][u] = w;
    }
    print_matrix();

    for (int k = 1; k <=3; k++)
    {
        for (int i = 1; i <= nodes; i++)
        {
            for (int j = 1; j <= nodes; j++)
            {
                if(dist[i][k] == INF | dist[k][j] == INF)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << endl
         << "-------------------------" << endl
         << "after floyd warshall call" << endl
         << "-------------------------" << endl;

    print_matrix();

    return 0;
}