#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e15;

int n, m, k, t, q;
int d[505][505];
set<int> a;

void floyd()
{
    for (int k = 0; k <= n; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            int *di = d[i];
            int dik;
            for (int j = 0; j <= n; j++)
            {
                dik = di[k];
                if (dik == INF)
                    continue;
                if (dik + d[k][j] < di[j])
                {
                    di[j] = dik + d[k][j];
                }
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            d[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z < d[x][y])
        {
            d[x][y] = z;
            d[y][x] = z;
        }
    }

    cin >> k >> t;

    a.clear();
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (a.count(i))
        {
            d[0][i] = t;
            d[i][0] = t;
        }
        else
        {
            d[0][i] = INF;
            d[i][0] = INF;
        }
    }
    d[0][0] = 0;

    floyd();

    cin >> q;
    while (q--)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            if (z < d[x][y])
            {
                d[x][y] = z;
                d[y][x] = z;
                floyd();
            }
        }
        else if (tp == 2)
        {
            int x;
            cin >> x;
            if (a.count(x) == 0)
            {
                a.insert(x);
                d[0][x] = t;
                d[x][0] = t;
                floyd();
            }
        }
        else
        {
            int64_t ans = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (d[i][j] < INF)
                    {
                        ans += d[i][j];
                    }
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
