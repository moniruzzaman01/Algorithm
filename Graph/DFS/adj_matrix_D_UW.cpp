#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges, i = 1;
    cin >> nodes >> edges;
    int arr[nodes][nodes];

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            arr[i][j] = 0;
        }
    }

    while(i++ <= edges)
    {
        int x, y;
        cin >> x >> y;
        // cout << x << " " << y << endl;
        arr[x-1][y-1] = 1;
    }

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


        return 0;
}