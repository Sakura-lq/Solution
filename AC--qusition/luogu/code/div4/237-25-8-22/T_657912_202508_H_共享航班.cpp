#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    int x = 0;
    unordered_map<string, int> hash;
    int a = 1;

    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            string s;
            cin >> s;
            hash[s] = a;
        }
        a++;
    }

    set<tuple<int, string, string, string>> set;

    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;

        string c = t.substr(0, 2);
        string d = t.substr(7, 3);
        string e = t.substr(11, 3);
        string f = t.substr(15, 5);

        int g;
        if (hash.count(c))
        {
            g = hash[c];
        }
        else
        {
            g = a++;
            hash[c] = g;
        }

        set.insert({g, d, e, f});
    }

    cout << set.size() << endl;
}

signed main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
