#include <bits/stdc++.h>
using namespace std;

void merge(int ar[1000], int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;

    int L[leftSize];
    int R[rightSize];

    //leftside copy array
    for (int i = 0; i < leftSize; i++)
    {
        L[i] = ar[l + i];
    }
    //rightside copy array
    for (int i = 0; i < rightSize; i++)
    {
        R[i] = ar[m + i + 1];
    }

    int i = 0, j = 0;//to iterate on copy array
    int current = l;//to handle the main array index
    while (i < leftSize && j < rightSize)
    {
        if(L[i]<R[j])
        {
            ar[current++] = L[i++];
        }
        else
        {
            ar[current++] = R[j++];
        }
    }
    while (i < leftSize)
    {
        ar[current++] = L[i++];
    }
    while (i < leftSize && j < rightSize)
    {
        ar[current++] = R[j++];
    }
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
    merge(ar, 0, 3, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

        return 0;
}