#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MAX = (1 << 20) + 5;
int n, m, x, t[(1ll << 20) + 1], ans[MAX], lg_2[MAX], st[MAX][20];

void solve()
{
    cin >> n >> m >> x;

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;

        ans[i] = t[num ^ x];
        t[num] = i;
    }

    lg_2[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        lg_2[i] = lg_2[i >> 1] + 1;
        st[i][0] = ans[i];
    }

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (m--)
    {
        int l, r;

        cin >> l >> r;
        int t = lg_2[r - l + 1];

        cout << (max(st[l][t], st[r - (1 << t) + 1][t]) >= l ? "yes" : "no") << endl;
    }
    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}