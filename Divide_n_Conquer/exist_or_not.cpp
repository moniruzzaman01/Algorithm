#include <bits/stdc++.h>
using namespace std;

void isExist(vector<int>v,int l, int r, int k)
{
    int mid = (r + l) / 2;
    if (v[mid] == k)
    {
        cout << mid << endl;
        return;
    }

    if(l>=r)
    {
        cout << "Not Found";
        return;
    }

    if (k > v[mid])
    {
        isExist(v, mid+1, r, k);
    }
    if(k < v[mid])
    {
        isExist(v, l, mid-1, k);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while(n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;
    isExist(v, 0, v.size()-1, k);

    return 0;
}