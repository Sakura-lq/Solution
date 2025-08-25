#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    long long ans = n;

    for (int c = 2; c <= a[n]; ++c)
    {
        int l = n, r = n;
        while (l - 1 >= 1 && a[l - 1] >= c)
        {
            --l;
        }
        while (r + 1 <= n && a[r + 1] >= c)
        {
            ++r;
        }
        ans += (r - l + 1);
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
