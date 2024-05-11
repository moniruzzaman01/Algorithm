#include <bits/stdc++.h>
using namespace std;
int flag = 0;
void isDuplicate(vector<int> v, int l, int r, int k)
{
    int mid = (r + l) / 2;
    if (v[mid] == k)
    {
        flag++;
        if(v[mid-1]==k)
            flag++;
        if(v[mid+1]==k)
            flag++;
        return;
    }

    if(l>=r)
    {
        return;
    }

    if (k > v[mid])
    {
        isDuplicate(v, mid+1, r, k);
    }
    if(k < v[mid])
    {
        isDuplicate(v, l, mid-1, k);
    }
}

int main()
{
    int n, i = 0;
    cin >> n;
    vector<int> v;
    while (i++ < n)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;
    isDuplicate(v, 0, n - 1, k);
    if(flag==2)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}