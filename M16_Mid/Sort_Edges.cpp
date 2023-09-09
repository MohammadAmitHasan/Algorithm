#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    while (e--)
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}