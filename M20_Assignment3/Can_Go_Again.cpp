#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1005;
const long long INF = 1e18 + 7;
vector<pii> g[N];
long long d[N];

int n, m;
bool hasCycle = false;

void bellman_ford(int s)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;

    d[s] = 0;

    for (int i = 1; i <= n; i++)
    {

        for (int u = 1; u <= n; u++)
        {
            for (pii vpair : g[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if (d[u] != INF && d[v] > d[u] + w)
                {
                    if (i == n)
                        hasCycle = true;

                    d[v] = d[u] + (long long)w;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    int source;
    cin >> source;

    bellman_ford(source);

    if (hasCycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int t;
        cin >> t;
        while (t--)
        {
            int destination;
            cin >> destination;
            if (d[destination] != INF)
                cout << d[destination] << endl;
            else
                cout << "Not Possible" << endl;
        }
    }

    return 0;
}