#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int n, m;
const int mod = 998244353;
int data[100005];
double t1[100005], t2[100005];

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    double u = k * v;
    while (k <= n)
    {
        t1[k] = fmod(t1[k] * v, mod);
        t2[k] = fmod(t2[k] * u, mod);
        k += lowbit(k);
    }
}

void add_(int l, int r)
{
    int v = r - l + 1;
    update(l, v);
    update(r + 1, -v);
}

double getsum(double *t, int k)
{
    double sum = 0;
    while (k > 0)
    {
        sum = fmod(sum * t[k], mod);
        k -= lowbit(k);
    }

    return sum;
}

double getsum_(int l, int r)
{
    return fmod((r + 1) * getsum(t1, r), mod) - fmod(l * getsum(t1, l - 1), mod) - fmod(getsum(t2, r) - getsum(t2, l - 1), mod);
}

void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        add_(i, i);
    }

    while (m--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int l, r;
            cin >> l >> r;

            add_(l, r);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << getsum_(l, r) << endl;
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