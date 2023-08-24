#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
vector<pii> g[N];
int d[N];

int n, m;
bool hasCycle = false;

void bellman_ford(int s)
{
    for (int i = 1; i < n; i++)
        d[i] = INF;

    d[s] = 0;

    // for (int i = 1; i < n; i++)
    for (int i = 1; i <= n; i++) // To detect cycle
    {
        // All edge relaxation
        for (int u = 1; u < n; u++)
        {
            for (pii vpair : g[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if (d[u] != INF && d[v] > d[u] + w)
                {
                    if (i == n)
                        hasCycle = true;

                    d[v] = d[u] + w;
                }
            }
        }
    }
}

// Complexity Normally O(ve)
// Sparse graph number of edge, node same O(n^2)
// In Complete graph O(n^3)

int main()
{
    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    bellman_ford(1);

    if (hasCycle)
        cout << "Has Cycle" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "Distance of " << i;
            cout << ": " << d[i] << endl;
        }
    }

    return 0;
}