#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    int tot = 1;
    for (int i = 0; i < k; i++)
    {
        tot *= n;
    }

    vector<string> v;
    v.reserve(tot);

    for (int num = 0; num < tot; num++)
    {
        int t = num;
        string cur = "";
        for (int i = 0; i < k; i++)
        {
            int id = t % n;
            t /= n;
            cur = s[id] + cur;
        }
        v.push_back(cur);
    }

    sort(v.begin(), v.end());

    cout << v[x - 1] << endl;
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
