#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int mod = 998244353;

int inv(int a, int m = mod)
{
    int b = m, u = 1, v = 0;
    while (b)
    {
        int t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    return (u + mod) % mod;
}

struct Seg
{
    int n;
    vector<int> t, lz;

    void push(int i, int l, int r)
    {
        if (lz[i] == -1)
        {
            return;
        }
        t[i] = lz[i] * (r - l + 1) % mod;
        if (l != r)
        {
            lz[i * 2] = lz[i];
            lz[i * 2 + 1] = lz[i];
        }
        lz[i] = -1;
    }

    void build(int i, int l, int r, const vector<int> &a)
    {
        lz[i] = -1;
        if (l == r)
        {
            t[i] = a[l] % mod;
            return;
        }
        int m = (l + r) / 2;
        build(i * 2, l, m, a);
        build(i * 2 + 1, m + 1, r, a);
        t[i] = (t[i * 2] + t[i * 2 + 1]) % mod;
    }

    void upd(int i, int l, int r, int ql, int qr, int v)
    {
        push(i, l, r);
        if (r < ql || l > qr)
        {
            return;
        }
        if (ql <= l && r <= qr)
        {
            lz[i] = v;
            push(i, l, r);
            return;
        }
        int m = (l + r) / 2;
        upd(i * 2, l, m, ql, qr, v);
        upd(i * 2 + 1, m + 1, r, ql, qr, v);
        t[i] = (t[i * 2] + t[i * 2 + 1]) % mod;
    }

    int qry(int i, int l, int r, int ql, int qr)
    {
        push(i, l, r);
        if (r < ql || l > qr)
        {
            return 0;
        }
        if (ql <= l && r <= qr)
        {
            return t[i];
        }
        int m = (l + r) / 2;
        return (qry(i * 2, l, m, ql, qr) + qry(i * 2 + 1, m + 1, r, ql, qr)) % mod;
    }

    void build(const vector<int> &a)
    {
        n = (int)a.size();
        t.resize(n * 4);
        lz.resize(n * 4, -1);
        build(1, 0, n - 1, a);
    }

    void update(int l, int r, int v)
    {
        upd(1, 0, n - 1, l, r, v);
    }

    int query(int l, int r)
    {
        return qry(1, 0, n - 1, l, r);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    vector<pair<int, int>> op(m);
    for (int i = 0; i < m; i++)
    {
        cin >> op[i].first >> op[i].second;
    }
    Seg seg;
    seg.build(a);
    for (int i = 0; i < m; i++)
    {
        int l = op[i].first - 1, r = op[i].second - 1;
        int length = r - l + 1;
        int s = seg.query(l, r);
        int iv = inv(length);
        seg.update(l, r, (s * iv) % mod);
    }
    for (int i = 0; i < n; i++)
    {
        cout << seg.query(i, i) << (i == n - 1 ? '\n' : ' ');
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
