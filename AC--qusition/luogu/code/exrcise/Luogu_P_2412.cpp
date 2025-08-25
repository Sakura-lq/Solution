#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int MAXN = 50005;
const int LOGN = 18;

vector<vector<string>> st(MAXN, vector<string>(LOGN + 1));
int Log2[MAXN + 1];

bool cmp(string a, string b)
{

    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    return a > b;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> data(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> data[i];
    }

    Log2[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        Log2[i] = Log2[i >> 1] + 1;
        st[i][0] = data[i];
    }

    for(int j = 1; j <= LOGN; j++)
    {
        for(int i = 1; i + (1 << (j - 1)) - 1 <= n; i++)
        {
            if(cmp(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]))
            {
                st[i][j] = st[i][j - 1];
            }
            else
            {
                st[i][j] = st[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        int t = Log2[r - l + 1];

        if(cmp(st[l][t], st[r - (1 << t) + 1][t]))
        {
            cout << st[l][t] << endl;
        }
        else
        {
            cout << st[r - (1 << t) + 1][t] << endl;
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