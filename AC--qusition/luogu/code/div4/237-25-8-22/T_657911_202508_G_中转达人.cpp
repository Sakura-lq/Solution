#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> Y(n, vector<int>(n));
    vector<vector<int>> T(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> Y[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> T[i][j];
        }
    }

    vector<vector<int>> mt(n, vector<int>(n, INF));

    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (u == v)
            {
                continue;
            }
            for (int w = 0; w < n; w++)
            {
                if (w == u || w == v)
                {
                    continue;
                }
                if (T[u][w] != -1 && T[w][v] != -1)
                {
                    mt[u][v] = min(mt[u][v], T[u][w] + T[w][v]);
                }
            }
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int an = INF;
        if (Y[u][v] != -1)
        {
            an = Y[u][v];
        }
        if (mt[u][v] != INF)
        {
            an = min(an, mt[u][v]);
        }
        cout << (an == INF ? -1 : an) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
