#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> mi(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mi[i][j];
        }
    }

    int d[5][2] = {
        {0, 0},
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}};

    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -2));

    function<int(int, int)> dfs = [&](int i, int j) -> int
    {
        if (i < 1 || i > n || j < 1 || j > m)
        {
            return 0;
        }

        if (vis[i][j] == 1)
        {
            return -1;
        }
        if (vis[i][j] == 2)
        {
            return dp[i][j];
        }

        vis[i][j] = 1;

        int dir = mi[i][j];
        int x = i + d[dir][0];
        int y = j + d[dir][1];

        int res = dfs(x, y);
        if (res == -1)
        {
            dp[i][j] = -1;
        }
        else
        {
            dp[i][j] = res + 1;
        }

        vis[i][j] = 2;
        return dp[i][j];
    };

    while (q--)
    {
        int i, j;
        cin >> i >> j;
        cout << dfs(i, j) << endl;
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
