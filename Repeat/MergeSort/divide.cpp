#include <bits/stdc++.h>
using namespace std;

void divide(int ar[1000],int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    divide(ar, l, mid);
    divide(ar, mid + 1, r);
}

int main()
{
    int n;
    cin >> n;
    int ar[1000];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ar[i] = x;
    }
    divide(ar, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ar[i] << " ";
    // }

    return 0;
}