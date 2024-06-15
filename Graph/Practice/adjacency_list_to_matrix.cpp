#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int adjM[N][N];

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= vertex; i++)
    {
        for (int j:adj[i])
        {
            // cout << "ij" << i << j << adj[i][j] << endl;
            adjM[i][j] = 1;
        }
    }
    for (int i = 1; i <= vertex; i++)
    {
        for (int j = 1; j <= vertex; j++)
        {
            cout << adjM[i][j] << " ";
        }
        cout << endl;
    }
    // for (int i = 1; i <= vertex; i++)
    // {
    //     cout << "level " << i << ": ";
    //     for (int j : adj[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    

    return 0;
}