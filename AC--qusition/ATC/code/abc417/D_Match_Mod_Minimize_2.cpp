#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    multiset<int> ms;
    for (auto &x : a)
    {
        ms.insert(x);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int need = (m - b[i]) % m;
        auto it = ms.lower_bound(need);
        if (it == ms.end())
        {
            it = ms.begin();
        }
        int val = *it;
        ms.erase(it);
        res += (val + b[i]) % m;
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
