#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MAXN = 1005;
int n, m;
int h[MAXN][MAXN];
int st[MAXN][MAXN][11];
int lg_2[MAXN];
int tal = 0;

void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> h[i][j];
            tal += h[i][j];
        }
    }

    lg_2[0] = -1;
    for (int i = 1; i <= max(n, m); i++)
    {
        lg_2[i] = lg_2[i / 2] + 1;
    }

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            st[i][j][0] = h[i][j];
        }
    }

    for (int kx = 1; (1 << kx) <= n; kx++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i + (1 << kx) - 1 <= n; i++)
            {
                st[i][j][kx] = min(st[i][j][kx - 1], st[i + (1 << (kx - 1))][j][kx - 1]);
            }
        }
    }

    auto getColMin = [&](int j, int x1, int x2) -> int
    {
        int k = lg_2[x2 - x1 + 1];
        return min(st[x1][j][k], st[x2 - (1 << k) + 1][j][k]);
    };

    auto check = [&](int k) -> bool
    {
        for (int i = 1; i + k - 1 <= n; i++)
        {
            for (int j = 1; j + k - 1 <= m; j++)
            {
                bool ok = true;
                for (int col = j; col < j + k; col++)
                {
                    if (getColMin(col, i, i + k - 1) < k)
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    return true;
                }
            }
        }
        return false;
    };

    int l = 1, r = min({n, m, 1000LL}), res = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << tal - res * res * res << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
