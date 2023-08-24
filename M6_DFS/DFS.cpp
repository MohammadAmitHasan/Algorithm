#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    // Section 1: Actions after just entering node u
    visited[u] = true;
    cout << "Visiting Node : " << u << endl;
    for (int v : adj[u])
    {
        // Section 2: Actions before entering new node
        if (visited[v])
            continue;
        dfs(v);
        // Section 3: Actions after exiting neighbour
    }
    // Section 4: Actions before exiting u
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    return 0;
}