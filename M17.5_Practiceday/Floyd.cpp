#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int d[N][N];
int n, m;
const int INF = 1e9 + 7;

void dist_initialise()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                d[i][j] = INF;
        }
    }
}

int main()
{
    cin >> n;

    dist_initialise();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int v;
            cin >> v;
            if (v != -1)
                d[i][j] = v;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int max = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] != INF)
                if (max < d[i][j])
                    max = d[i][j];
        }
    }
    cout << max;

    return 0;
}