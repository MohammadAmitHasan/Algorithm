#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int A[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        if (m == 1000)
            cout << "YES" << endl;
        else
        {
            int remaining_marks = 1000 - m;

            bool dp[n + 1][remaining_marks + 1];
            dp[0][0] = true;
            for (int i = 1; i <= remaining_marks; i++)
            {
                dp[0][i] = false;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= remaining_marks; j++)
                {
                    if (A[i - 1] <= j)
                    {
                        dp[i][j] = dp[i][j - A[i - 1]] || dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }

            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= remaining_marks; j++)
                {
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }

            if (dp[n][remaining_marks])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}