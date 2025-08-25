#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int x, a, b, t;
    cin >> x >> a >> b >> t;

    if (x < 60)
    {
        cout << 0 << "\n";
    }
    else if (x < 120)
    {
        cout << a << "\n";
    }
    else if (x < 240)
    {
        cout << b << "\n";
    }
    else
    {
        cout << t << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
