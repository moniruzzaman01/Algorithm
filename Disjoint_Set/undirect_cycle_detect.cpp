#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parentSize[1000];
void dsu_set(int childrenNumber)
{
    for (int i = 0; i <= childrenNumber; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while(parent[node]!=-1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if(leaderA!=leaderB)
    {
        if(parentSize[leaderA]>parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA==leaderB)
        {
            cout << "cycle detected between: " << a << " " << b << endl;
        }
        else 
        {
            dsu_union(a, b);
        }
    }
    cout << "parents: ";
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl
         << "parent sizes: ";
    for (int i = 0; i < n; i++)
    {
        cout << parentSize[i] << " ";
    }

        return 0;
}