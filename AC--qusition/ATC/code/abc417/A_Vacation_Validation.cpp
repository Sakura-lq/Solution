#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;

    for (int i = l - 1; i <= r - 1; ++i)
    {
        if (s[i] != 'o')
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main()
{
    solve();
    return 0;
}
