#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c[i]; j++)
        {
            if (i == 1 || j == 1 || j == c[i] || (i * j) % 10 == 6)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
