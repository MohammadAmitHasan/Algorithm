#include <bits/stdc++.h>
using namespace std;

// Complexity O(2^n)
int fibonacci(int n)
{
    if (n <= 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
    // if (n == 1 || n == 0)
    //     return 1;
    // int ans1 = fibonacci(n - 1);
    // int ans2 = fibonacci(n - 2);
    // return ans1 + ans2;
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}