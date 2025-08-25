#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n, m;
const int MAXN = (1 << 12) + 5;
int t1[MAXN][MAXN];

int lowbit(int x)
{
    return x & -x;
}

void update(int x, int y, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        for (int j = y; j <= m; j += lowbit(j))
        {
            t1[i][j] += v;
        }
    }
}

void add_(int a, int b, int c, int d, int k)
{
    update(a, b, k);
    update(a, d + 1, -k);
    update(c + 1, b, -k);
    update(c + 1, d + 1, k);
}

int query(int x, int y)
{
    int res = 0;

    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            res += t1[i][j];
        }
    }

    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int op;
    while (cin >> op)
    {
        if (op == 1)
        {
            int a, b, c, d, k;
            cin >> a >> b >> c >> d >> k;
            add_(a, b, c, d, k);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(x, y) << endl;
        }
    }

    return 0;
}
