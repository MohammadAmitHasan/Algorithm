#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 105;
const int INF = 1e8;
vector<pii> g[N];
int d[N];

int n, m;

void bellman_ford(int s)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;

    d[s] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (pii vpair : g[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                }
            }
        }
    }
}

int main()
{
    int s;
    cin >> n >> m >> s;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    bellman_ford(s);

    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";

    return 0;
}
