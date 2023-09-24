#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int m;
        cin >> m;

        int remaining_marks = 1000 - m;

        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        if (remaining_marks == 0)
        {
            cout << "1" << endl;
        }
        else
        {
            int dp[n + 1][remaining_marks + 1];
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= remaining_marks; j++)
                {
                    if (A[i - 1] <= j)
                    {
                        dp[i][j] = dp[i][j - A[i - 1]] + dp[i - 1][j];
                        dp[i][j] %= 1000000007;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }

            cout << dp[n][remaining_marks] << endl;
        }
    }
    return 0;
}