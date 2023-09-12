for (int i = 2; i <= N; i++)
    {
        if (i % 3 == 0 && dp[i / 3])
        {
            dp[i] = true;
        }
        if (i % 2 == 0 && dp[i / 2])
        {
            dp[i] = true;
        }
    }