#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    vector<int> a;
    vector<int> b;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++)
    {
        if(binary_search(a.begin(), a.end(), b[i]))
        {
            auto it = lower_bound(a.begin(), a.end(), b[i]);
            a.erase(it); 
        }
    }

    for(int x : a)
    {
        cout << x << " ";
    }
    cout << endl;

    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
