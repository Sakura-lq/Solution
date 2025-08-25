#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    int ti = 0;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for(int x : p)
    {
        if(x == 1)
        {
            cout << cnt << ' ' << ti << endl;
            break;
        }
        else if(x == 0)
        {
            ti++;
        }
        cnt++;
    }
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