#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string S;
    cin >> S;
    int n = S.size();
    double max_rate = 0.0;

    for (int i = 0; i < n; ++i)
    {
        if (S[i] != 't')
        {
            continue;
        }

        for (int j = i + 2; j < n; ++j)
        {
            if (S[j] != 't')
            {
                continue;
            }

            int t_count = 0;
            for (int k = i; k <= j; ++k)
            {
                if (S[k] == 't')
                {
                    t_count++;
                }
            }

            int len = j - i + 1;
            double cur_rate = (t_count - 2.0) / (len - 2.0);
            if (cur_rate > max_rate)
            {
                max_rate = cur_rate;
            }
        }
    }

    cout << fixed << setprecision(15) << max_rate << endl;
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
