#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int,int> > adj[N];

int main()
{
    int node, edges;
    cin >> node >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    for (int i = 1; i <= node; i++)
    {
        cout << "Node " << i << ": ";
        for (pair<int,int> j : adj[i])
        {
            cout << "{" << j.first << "," << j.second << "} ";
        }
        cout << endl;
    }

        return 0;
}