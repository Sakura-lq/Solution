#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int MAXN = 2000005;
const int LOGN = 22;

int st[MAXN][LOGN], Logn[MAXN];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> data(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> data[i];
    }

    Logn[0] = -1;

    for (int i = 1; i <= n; i++)
    {
        st[i][0] = data[i];
        Logn[i] = Logn[i >> 1] + 1;
    }

    for (int j = 1; j <= LOGN; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << 0 << endl;
            continue;
        }

        int left = max(1LL, i - m);
        int right = i - 1;

        int t = Logn[right - left + 1];

        cout << min(st[left][t], st[right - (1 << t) + 1][t]) << endl;
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