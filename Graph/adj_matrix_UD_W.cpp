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
        int x, y, z;
        cin >> x >> y >> z;
        // cout << x << " " << y << endl;
        arr[x-1][y-1] = z;
        arr[y-1][x-1] = z;
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