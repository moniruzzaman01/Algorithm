#include <bits/stdc++.h>
using namespace std;

int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};
void find(int node)
{
    int temp = node;
    while(parent[temp]!=-1)
    {
        temp = parent[temp];
    }
    cout << temp;
}
int main()
{
    find(1);

    return 0;
}