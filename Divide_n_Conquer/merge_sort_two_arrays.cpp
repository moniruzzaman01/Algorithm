#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&v, vector<int> v1,vector<int> v2)
{
    int l1 = v1.size();
    int l2 = v2.size();
    int i = 0, j = 0;

    while (i<l1 && j<l2)
    {
        if(v1[i] >= v2[j])
            v.push_back(v1[i++]);
        else
            v.push_back(v2[j++]);
    }
    while (i<l1)
    {
        v.push_back(v1[i++]);
    }
    while (j<l2)
    {
        v.push_back(v2[j++]);
    }
}
int main()
{
    int n, m;
    vector<int> v, v1, v2;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    cin >> m;
    while (m--)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    merge(v, v1, v2);
    for (int i : v)
        cout << i << " ";


            return 0;
}