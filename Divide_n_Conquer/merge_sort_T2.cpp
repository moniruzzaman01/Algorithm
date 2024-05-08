#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];

void merge(int l, int mid, int r)
{
    // cout << "l" << l << "mid" << mid << "r" << r << endl;
    int left = mid - l + 1;
    int right = r - (mid + 1) + 1;
    int ar1[left + 1];
    int ar2[right + 1];

    ar1[left] = INT_MAX;
    ar2[right] = INT_MAX;

    for (int i = l, j = 0; i <= mid; i++)
    {
        ar1[j++] = arr[i];
    }
    for (int i = mid+1, j = 0; i <= r; i++)
    {
        ar2[j++] = arr[i];
    }
    int merged_array[left + right];
    for (int i = 0,j=0,k=0; i < left + right; i++)
    {
        if(ar1[j]<=ar2[k])
        {
            merged_array[i] = ar1[j++];
        }
        else
        {
            merged_array[i] = ar2[k++];
        }
    }

    for (int i = 0, j = l; i < left + right; i++, j++)
    {
        arr[j] = merged_array[i];
    }

    //     for (int i : ar1)
    //         cout << i << " ";
    // cout << endl;
    // for (int i : ar2)
    //     cout << i << " ";
    // cout << endl;
    // for (int i : merged_array)
    //     cout << i << " ";
    // cout << endl
    //      << endl;
}
void divide(int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    divide(l, mid);
    divide(mid + 1, r);
    merge(l, mid, r);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    divide(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}