#include <iostream>
using namespace std;
using ll = long long;

int n, m;
ll mod;
ll a[100005], sum[400005], mul[400005], laz[400005];

void up(int i)
{
    sum[i] = (sum[(i << 1)] + sum[(i << 1) | 1]) % mod;
}

void pd(int i, int s, int t)
{
    int l = (i << 1), r = (i << 1) | 1, mid = (s + t) >> 1;
    if (mul[i] != 1)
    {
        mul[l] *= mul[i];
        mul[l] %= mod;
        mul[r] *= mul[i];
        mul[r] %= mod;
        laz[l] *= mul[i];
        laz[l] %= mod;
        laz[r] *= mul[i];
        laz[r] %= mod;
        sum[l] *= mul[i];
        sum[l] %= mod;
        sum[r] *= mul[i];
        sum[r] %= mod;
        mul[i] = 1;
    }
    if (laz[i])
    {
        sum[l] += laz[i] * (mid - s + 1);
        sum[l] %= mod;
        sum[r] += laz[i] * (t - mid);
        sum[r] %= mod;
        laz[l] += laz[i];
        laz[l] %= mod;
        laz[r] += laz[i];
        laz[r] %= mod;
        laz[i] = 0;
    }
    return;
}

void build(int s, int t, int i)
{
    mul[i] = 1;
    if (s == t)
    {
        sum[i] = a[s];
        return;
    }
    int mid = s + ((t - s) >> 1);
    build(s, mid, i << 1);
    build(mid + 1, t, (i << 1) | 1);
    up(i);
}

void chen(int l, int r, int s, int t, int i, ll z)
{
    int mid = s + ((t - s) >> 1);
    if (l <= s && t <= r)
    {
        mul[i] *= z;
        mul[i] %= mod;
        laz[i] *= z;
        laz[i] %= mod;
        sum[i] *= z;
        sum[i] %= mod;
        return;
    }
    pd(i, s, t);
    if (mid >= l)
        chen(l, r, s, mid, (i << 1), z);
    if (mid + 1 <= r)
        chen(l, r, mid + 1, t, (i << 1) | 1, z);
    up(i);
}

void add(int l, int r, int s, int t, int i, ll z)
{
    int mid = s + ((t - s) >> 1);
    if (l <= s && t <= r)
    {
        sum[i] += z * (t - s + 1);
        sum[i] %= mod;
        laz[i] += z;
        laz[i] %= mod;
        return;
    }
    pd(i, s, t);
    if (mid >= l)
        add(l, r, s, mid, (i << 1), z);
    if (mid + 1 <= r)
        add(l, r, mid + 1, t, (i << 1) | 1, z);
    up(i);
}

ll getans(int l, int r, int s, int t, int i)
{
    int mid = s + ((t - s) >> 1);
    ll tot = 0;
    if (l <= s && t <= r)
        return sum[i];
    pd(i, s, t);
    if (mid >= l)
        tot += getans(l, r, s, mid, (i << 1));
    tot %= mod;
    if (mid + 1 <= r)
        tot += getans(l, r, mid + 1, t, (i << 1) | 1);
    return tot % mod;
}

void solve()
{
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m >> mod;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, n, 1);

    while (m--)
    {
        int l, r, op;
        ll k;
        cin >> op;

        if(op == 1)
        {
            cin >> l >> r >> k;
            chen(l, r, 1, n, 1, k);
        }
        else if(op == 2)
        {
            cin >> l >> r >> k;
            add(l, r, 1, n, 1, k);
        }
        else if(op == 3)
        {
            ll sum = 0;
            cin >> l >> r;
            sum = getans(l, r, 1, n, 1);
            cout << sum << endl;
        }
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