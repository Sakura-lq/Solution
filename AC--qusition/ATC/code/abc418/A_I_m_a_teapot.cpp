#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string s;
    int n;
    cin >> n;
    cin.ignore();
    cin >> s;

    if (n < 3)
    {
        cout << "No" << endl;
        return;
    }
    if (s.substr(n - 3) == "tea")
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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
