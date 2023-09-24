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
            cout << "0" << endl;
        }
        else
        {

            int dp[n + 1][remaining_marks + 1];
            dp[0][0] = 0;
            for (int i = 1; i <= remaining_marks; i++)
                dp[0][i] = INT_MAX - 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= remaining_marks; j++)
                {
                    if (A[i - 1] <= j)
                    {
                        dp[i][j] = min(1 + dp[i][j - A[i - 1]], dp[i - 1][j]);
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }

            if (dp[n][remaining_marks] == INT_MAX - 1)
                cout << "-1" << endl;
            else
                cout << dp[n][remaining_marks] << endl;
        }
    }
    return 0;
}