#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
int f[100005][17], LOG[100006];

void pre()
{
    LOG[1] = 0;
    LOG[2] = 1;

    for (int i = 3; i < 100005; i++)
    {
        LOG[i] = LOG[i / 2] + 1;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i][0];
    }

    pre();

    for (int j = 1; j <= 17; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        int s = LOG[r - l + 1];

        cout << max(f[l][s], f[r - (1 << s) + 1][s]) << endl;
    }
    return;
}   

signed main()
{
    int T = 1;
    cin.tie(nullptr)->sync_with_stdio(false);
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}