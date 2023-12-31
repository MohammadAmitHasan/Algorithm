#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adj[N][N];

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // adj[u][v] = 1; // Unweighted
        adj[u][v] = w;
        // adj[v][u] = 1; // If undirected
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}