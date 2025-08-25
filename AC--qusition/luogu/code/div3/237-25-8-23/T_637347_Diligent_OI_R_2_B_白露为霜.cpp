#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    if (n == 1)
    {
        cout << "Yes\n";
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] & 1) != (b[i] & 1))
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
