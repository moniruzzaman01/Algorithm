#include <bits/stdc++.h>
using namespace std;

void merge(int ar[1000], int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;

    int L[leftSize];
    int R[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        L[i] = ar[l + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        R[i] = ar[m + 1 + i];
    }

    int i = 0, j = 0, curr = l;
    while(i<leftSize && j<rightSize)
    {
        if(L[i]<R[j])
        {
            ar[curr++] = L[i++];
        }
        else
        {
            ar[curr++] = R[j++];
        }
    }
    while(i<leftSize)
    {
        ar[curr++] = L[i++];
    }
    while(j<rightSize)
    {
        ar[curr++] = R[j++];
    }
}

void mergeSort(int ar[1000], int l, int r)
{
    if(l==r)
        return;
    int mid = (l + r) / 2;
    mergeSort(ar, l, mid);
    mergeSort(ar, mid + 1, r);
    merge(ar, l, mid, r);
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
    mergeSort(ar, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

        return 0;
}