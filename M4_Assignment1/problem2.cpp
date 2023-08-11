#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int searchValue;
    cin >> searchValue;

    int l = 0;
    int r = n - 1;
    int position = -1;

    while (l <= r)
    {
        int mid_index = (l + r) / 2;
        if (arr[mid_index] == searchValue)
        {
            position = mid_index;
            break;
        }
        if (searchValue > arr[mid_index])
            l = mid_index + 1;
        else
            r = mid_index - 1;
    }

    if (position > -1)
        cout << position << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}