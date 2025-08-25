#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    int ju[n][m];
    vector<vector<int>> pre_sum(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ju[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pre_sum[i][j] = ju[i - 1][j - 1] + pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1];
        }
    }

    int max_k = 0;
    for (int k = 1; k <= min(n, m); k++)
    {
        for (int i = k; i <= n; i++)
        {
            for (int j = k; j <= m; j++)
            {
                int x1 = i - k + 1;
                int y1 = j - k + 1;
                int he = pre_sum[i][j] - pre_sum[x1 - 1][j] - pre_sum[i][y1 - 1] + pre_sum[x1 - 1][y1 - 1];
                if (he == k * k)
                {
                    max_k = k;
                }
            }
        }
    }
    cout << max_k << endl;
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