#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int r, int mid)
{
    vector<int> leftV;
    vector<int> rightV;

    for (int i = l; i <= mid; i++)
    {
        leftV.push_back(v[i]);
    }
    for (int i = mid + 1; i <= r; i++)
    {
        rightV.push_back(v[i]);
    }

    leftV.push_back(INT_MAX);
    rightV.push_back(INT_MAX);

    int lp = 0, rp = 0;

    for (int i = l; i <= r; i++)
    {
        if (leftV[lp] <= rightV[rp])
        {
            v[i] = leftV[lp];
            lp++;
        }
        else
        {
            v[i] = rightV[rp];
            rp++;
        }
    }
}

void mergeSort(vector<int> &v, int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(v, l, mid);
    mergeSort(v, mid + 1, r);
    merge(v, l, r, mid);
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }

    mergeSort(v, 0, v.size() - 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}