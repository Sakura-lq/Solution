#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int n, m;
int t1[500005], t2[500005];

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    int u = k * v;
    while(k <= n)
    {
        t1[k] += v;
        t2[k] += u;
        k += lowbit(k);
    }
}

void add_(int l, int r, int v)
{
    update(l, v);
    update(r + 1, -v);
}

int getsum(int* t, int k)
{
    int sum = 0;
    while(k > 0)
    {
        sum += t[k];
        k -= lowbit(k);
    }

    return sum;
}

int getsum_(int l, int r)
{
    return (r + 1) * getsum(t1, r) - l * getsum(t1, l - 1) - (getsum(t2, r) - getsum(t2, l - 1));
}

void solve()
{
    cin >> n >> m;

    int data[n + 1];

    for(int i = 1; i <= n; i++)
    {
        cin >> data[i];
        add_(i, i, data[i]);
    }

    while(m--)
    {
        int op;
        cin >> op;

        if(op == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;

            add_(l, r, k);
        }
        else
        {
            int x;
            cin >> x;
            cout << getsum_(x, x) << endl;
        }
    }
    return ;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}