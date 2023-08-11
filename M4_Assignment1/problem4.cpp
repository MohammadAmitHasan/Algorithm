#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array1Size, array2Size;
    vector<int> arr1, arr2, result;
    cin >> array1Size;
    int val;
    for (int i = 0; i < array1Size; i++)
    {
        cin >> val;
        arr1.push_back(val);
    }

    cin >> array2Size;
    for (int i = 0; i < array2Size; i++)
    {
        cin >> val;
        arr2.push_back(val);
    }

    arr1.push_back(INT_MIN);
    arr2.push_back(INT_MIN);

    int la = 0, ra = 0;

    for (int i = 0; i < array1Size + array2Size; i++)
    {
        if (arr1[la] > arr2[ra])
        {
            result.push_back(arr1[la]);
            la++;
        }
        else
        {
            result.push_back(arr2[ra]);
            ra++;
        }
    }

    for (int i = 0; i < array1Size + array2Size; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}