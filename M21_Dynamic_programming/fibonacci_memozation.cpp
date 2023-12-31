#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll save[N];

// Complexity O(2^n)
ll fibonacci(int n)
{
    if (n <= 1)
        return 1;
    // Memoization
    if (save[n] != -1)
    {
        return save[n];
    }
    ll ans1 = fibonacci(n - 1);
    ll ans2 = fibonacci(n - 2);
    save[n] = ans1 + ans2;
    return save[n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        save[i] = -1;
    }

    cout << fibonacci(n) << endl;
    return 0;
}