#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int logN = 21;
const int MAXN = 100005;

int f[MAXN][logN], Logn[MAXN];
int bak[MAXN], left_[MAXN], right_[MAXN];

void solve()
{
    int n, q;
    cin >> n;
    while (n != 0)
    {
        memset(bak, 0, sizeof(bak));
        memset(left_, 0, sizeof(left_));
        memset(right_, 0, sizeof(right_));
        cin >> q;
        vector<int> data(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> data[i];
        }

        int cnt = 0;
        data[0] = -100005;
        for (int i = 1; i <= n; i++)
        {
            if (data[i - 1] != data[i])
            {
                right_[cnt] = i - 1;
                left_[++cnt] = i;
            }
            bak[i] = cnt;
        }

        Logn[0] = -1;
        right_[cnt] = n;
        for (int i = 1; i <= cnt; i++)
        {
            Logn[i] = Logn[i >> 1] + 1;
            f[i][0] = right_[i] - left_[i] + 1;
        }

        for (int j = 1; j <= logN; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= cnt; i++)
            {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }

        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;

            if (l > r)
            {
                swap(l, r);
            }

            int l_b = bak[l];
            int r_b = bak[r];

            if (l_b == r_b)
            {
                cout << r - l + 1 << endl;
                continue;
            }

            int a = right_[l_b] - l + 1;
            int b = r - left_[r_b] + 1;
            int c = max(a, b);

            if (l_b + 1 < r_b)
            {
                int l_to = l_b + 1;
                int r_to = r_b - 1;
                int m = Logn[r_to - l_to + 1];
                c = max(max(f[l_to][m], f[r_to - (1 << m) + 1][m]), c);
            }
            cout << c << endl;
        }

        cin >> n;
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