#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int t[500005];
int n, m;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= n)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int getsum(int k)
{
    int sum = 0;
    while (k > 0)
    {
        sum += t[k];
        k -= lowbit(k);
    }

    return sum;
}

void solve()
{
    cin >> n >> m;

    int data[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> data[i];
        update(i, data[i]);
    }

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, v;
            cin >> x >> v;
            update(x, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            cout << getsum(r) - getsum(l - 1) << endl;
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