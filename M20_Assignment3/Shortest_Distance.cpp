#include <bits/stdc++.h>
using namespace std;

const int N = 105;
long long d[N][N];
int n, m;
const long long INF = 1e18 + 5;

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
    cin >> n >> m;

    dist_initialise();

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (d[u][v] > w)
        {
            d[u][v] = w;
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

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (d[x][y] == INF)
            cout << -1 << endl;
        else
            cout << d[x][y] << endl;
    }

    return 0;
}