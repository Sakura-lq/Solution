#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> hash;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int left = i - a[i];
        if (hash.count(left))
        {
            cnt += hash[left];
        }
        int right = i + a[i];
        hash[right]++;
    }

    cout << cnt << endl;
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
