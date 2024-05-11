#include <bits/stdc++.h>
using namespace std;

void conquer(vector<int>&arr, int si, int mid, int ei)
{
    int merged_arr[ei - si + 1];

    int idx1 = si;
    int idx2 = mid + 1;
    int temp_idx = 0;

    while(idx1<=mid && idx2<=ei)
    {
        if(arr[idx1] <= arr[idx2])
        {
            merged_arr[temp_idx++] = arr[idx1++];
        }
        else
        {
            merged_arr[temp_idx++] = arr[idx2++];
        }

    }

    while(idx1<=mid)
        merged_arr[temp_idx++] = arr[idx1++];
    while(idx2<=ei)
        merged_arr[temp_idx++] = arr[idx2++];

    for (int i = 0, j = si; i < (ei - si + 1); i++, j++)
    {
        arr[j] = merged_arr[i];
    }
}


void divide(vector<int> &arr, int si, int ei)
{
    if(si>=ei)
        return;
    int mid = si + (ei - si) / 2;
    divide(arr, si, mid);
    divide(arr, mid + 1, ei);
    conquer(arr, si, mid, ei);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    divide(arr, 0, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }

    return 0;
}