#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    char x, y;
    int a;
    cin >> x >> y >> a;

    string s;

    if (x == 'A')
    {
        if (y == 'N' && a == 2)
        {
            s = "A320";
        }
        else if (y == 'W' && a == 2)
        {
            s = "A350";
        }
        else if (y == 'W' && a == 4)
        {
            s = "A380";
        }
    }
    else if (x == 'B')
    {
        if (y == 'N' && a == 2)
        {
            s = "B737";
        }
        else if (y == 'W' && a == 2)
        {
            s = "B787";
        }
        else if (y == 'W' && a == 4)
        {
            s = "B747";
        }
    }
    else if (x == 'C')
    {
        if (y == 'N' && a == 2)
        {
            s = "C919";
        }
    }

    cout << s << endl;
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
