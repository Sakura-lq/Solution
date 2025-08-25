#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
int n;

const int MAXN = 1000005;
int t1[MAXN], t2[MAXN];

int lowbit(int x)
{
    return x & (-x);
}

void add(int k, int v)
{
    int u = k * v;
    while (k <= n)
    {
        t1[k] += v;
        t2[k] += u;

        k += lowbit(k);
    }
}

int getsum(int *t, int k)
{
    int sum = 0;
    while (k > 0)
    {
        sum += t[k];
        k -= lowbit(k);
    }

    return sum;
}

void add_qu(int l, int r, int v)
{
    add(l, v);
    add(r + 1, -v);
}

int getsum_(int l, int r)
{
    return (r + 1) * getsum(t1, r) - l * getsum(t1, l - 1) - (getsum(t2, r) - getsum(t2, l - 1));
}

void solve()
{
    int q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        add_qu(i, i, a[i]);
    }

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;

            add_qu(l, r, x);
        }
        else
        {
            int l;
            cin >> l;

            cout << getsum_(l, l) << endl;
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