#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> j(n);
    vector<int> f(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> j[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(0LL, (f[i] - abs(p[i] - j[i])));
    }

    cout << ans << endl;
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