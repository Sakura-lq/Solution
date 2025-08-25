#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int MAXN = 100005;
const int LOGN = 18;
int st[MAXN][LOGN + 1], Log2[MAXN + 1];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> data(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> data[i];
    }

    Log2[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        st[i][0] = data[i];
        Log2[i] = Log2[i >> 1] + 1;
    }

    for (int j = 1; j <= LOGN; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = m; i <= n; i++)
    {
        int l = i - m + 1;
        int r = i;

        int t = Log2[r - l + 1];

        cout << min(st[l][t], st[r - (1 << t) + 1][t]) << endl;
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