#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MAXN = 100005;
int st[MAXN][17];
int lg_2[MAXN];

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<int> data(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> data[i];
    }


    lg_2[0] = -1;
    for(int i = 1; i <= m; i++)
    {
        lg_2[i] = lg_2[i >> 1] + 1;
        st[i][0] = data[i];
    }

    for(int j = 1; (1 << j) <= m; j++)
    {
        for(int i = 1; i + (1 << j) - 1 <= m; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        int t = lg_2[r - l + 1];

        cout << min(st[l][t], st[r - (1 << t) + 1][t]) << ' ';
    }

    cout << endl;
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