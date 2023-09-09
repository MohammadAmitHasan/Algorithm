#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
vector<pii> g[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (pii vpair : g[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v])
                continue;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    int source;
    cin >> source;
    dijkstra(source);

    int t;
    cin >> t;
    while (t--)
    {
        int d, dw;
        cin >> d >> dw;
        if (dist[d] <= dw)
            cout << "YES " << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}