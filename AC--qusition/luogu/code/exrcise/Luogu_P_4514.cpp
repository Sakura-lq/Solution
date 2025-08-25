#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int n, m;
const int MAXN = 2053;
int t1[MAXN][MAXN], t2[MAXN][MAXN], t3[MAXN][MAXN], t4[MAXN][MAXN];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int y, int v)
{
    for(int i = x; i <= n; i += lowbit(i))
    {
        for(int j = y; j <= m; j += lowbit(j))
        {
            t1[i][j] += v;
            t2[i][j] += v * x;
            t3[i][j] += v * y;
            t4[i][j] += v * x * y;
        }
    }
}

void add_(int x1, int y1, int x2, int y2, int v)
{
    add(x1, y1, v);
    add(x1, y2 + 1, -v);
    add(x2 + 1, y1, -v);
    add(x2 + 1, y2 + 1, v);
}

int getsum(int x, int y)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            sum += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] - (x + 1) * t3[i][j] + t4[i][j];
        }
    }

    return sum;
}

int query(int x1, int y1, int x2, int y2)
{
    return getsum(x2, y2) - getsum(x2, y1 - 1) - getsum(x1 - 1, y2) + getsum(x1 - 1, y1 - 1);
}

void solve()
{
    char op;
    cin >> op >> n >> m;

    while(cin >> op)
    {
        if(op == 'L')
        {
            int a, b, c, d, k;
            cin >> a >> b >> c >> d >> k;

            add_(a, b, c, d, k);
        }
        else
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            cout << query(a, b, c, d) << endl;
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