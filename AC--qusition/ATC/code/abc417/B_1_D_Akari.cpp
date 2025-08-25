#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string s;
    cin >> s;

    string t = s; 
    bool can = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '#')
        {
            t[i] = '#';
            can = true;
        }
        else
        {
            if (can)
            {
                t[i] = 'o';
                can = false; 
            }
            else
            {
                t[i] = '.';
            }
        }
    }

    cout << t << endl;
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
