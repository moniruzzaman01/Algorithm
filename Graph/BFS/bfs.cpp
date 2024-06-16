#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector<int> v[N];
bool visited[N];

void bfs(int n)
{
    // start the queue
    queue<int> q;
    q.push(n);
    visited[n] = true;
    // traverse the queue
    while (!q.empty())
    {
        //take the first element of the remaining queue
        int x = q.front();
        q.pop();

        //print the first element of the remaining queue
        cout << x << " ";

        //traverse the node
        for(int j:v[x])
        {
            if(visited[j])
                continue;
            // push the node's elements
            //  cout << "push" << p << " " << j << endl;
            q.push(j);
            visited[j] = true;
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    bfs(1);

    return 0;
}