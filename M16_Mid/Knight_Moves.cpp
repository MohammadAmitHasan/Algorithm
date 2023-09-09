#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 105;
int visited[N][N];
int dist[N][N];
vector<pii> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj, int n, int m)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    dist[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : moves)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj, n, m) && !visited[ni][nj])
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                dist[ni][nj] = dist[i][j] + 1;
            }
        }
    }
}

void reset_dist_vis(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = -1;
            visited[i][j] = false;
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, si, sj, di, dj;
        cin >> n >> m >> si >> sj >> di >> dj;
        reset_dist_vis(n, m);

        if (isValid(di, dj, n, m))
        {
            bfs(si, sj, n, m);
        }

        cout << dist[di][dj] << endl;
    }

    return 0;
}