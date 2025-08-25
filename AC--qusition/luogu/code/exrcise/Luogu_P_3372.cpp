#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int d[400000], b[400000], a[100005], n;

void bulid(int l, int r, int p)
{
    if (l == r)
    {
        d[p] = a[l];
        return;
    }

    int m = l + ((r - l) >> 1);
    bulid(l, m, 2 * p);
    bulid(m + 1, r, 2 * p + 1);
    d[p] = d[2 * p] + d[2 * p + 1];
}

void updata(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        d[p] += (t - s + 1) * c;
        b[p] += c;
        return;
    }

    int m = s + ((t - s) >> 1);
    if (b[p])
    {
        d[2 * p] += b[p] * (m - s + 1);
        d[2 * p + 1] += b[p] * (t - m);
        b[2 * p] += b[p];
        b[2 * p + 1] += b[p];

        b[p] = 0;
    }

    if (l <= m)
    {
        updata(l, r, c, s, m, 2 * p);
    }
    if (r > m)
    {
        updata(l, r, c, m + 1, t, 2 * p + 1);
    }

    d[p] = d[2 * p] + d[2 * p + 1];
}

int getsum(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        return d[p];
    }

    int m = s + ((t - s) >> 1);
    if (b[p])
    {
        d[2 * p] += b[p] * (m - s + 1);
        d[2 * p + 1] += b[p] * (t - m);
        b[2 * p] += b[p];
        b[2 * p + 1] += b[p];

        b[p] = 0;
    }

    int sum = 0;

    if (l <= m)
    {
        sum += getsum(l, r, s, m, 2 * p);
    }
    if (r > m)
    {
        sum += getsum(l, r, m + 1, t, 2 * p + 1);
    }

    return sum;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    bulid(1, n, 1);

    int l, r, op, sum, k;

    while (m--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> k;
            updata(l, r, k, 1, n, 1);
        }
        else if (op == 2)
        {
            cin >> l >> r;
            sum = getsum(l, r, 1, n, 1);

            cout << sum << endl;
        }
    }
    return;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}