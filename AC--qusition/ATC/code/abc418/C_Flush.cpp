#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    const int MAX = 1000000;
    vector<int> freq(MAX + 2, 0);
    for (int x : a)
    {
        freq[x]++;
    }

    vector<int> pc(MAX + 2, 0);
    vector<int> ps(MAX + 2, 0);
    for (int i = 1; i <= MAX + 1; i++)
    {
        pc[i] = pc[i - 1] + freq[i];
        ps[i] = ps[i - 1] + i * freq[i];
    }

    auto sum_min = [&](int x) -> int
    {
        if (x <= 0)
        {
            return 0;
        }
        if (x > MAX + 1)
        {
            x = MAX + 1;
        }
        int total = pc[MAX + 1];
        return ps[x] + x * (total - pc[x]);
    };

    while (q--)
    {
        int b;
        cin >> b;
        int val = sum_min(b - 1);
        int x = max(b, val + 1);
        if (x > sum)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << x << endl;
        }
    }
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
