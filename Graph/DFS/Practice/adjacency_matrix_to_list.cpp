#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adj[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            adj[i][j] = x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (int j = 1; j <= n; j++)
        {
            if(adj[i][j]==1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

        return 0;
}