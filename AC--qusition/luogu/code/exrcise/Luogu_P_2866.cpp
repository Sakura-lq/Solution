// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define double long double
// #define endl '\n'
// const int MAXN = 80005;
// const int LOGN = 18;
// int st[MAXN][LOGN + 1], Log2[MAXN + 1];

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> data(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> data[i];
//     }

//     Log2[0] = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         Log2[i] = Log2[i >> 1] + 1;
//         st[i][0] = data[i];
//     }

//     for (int j = 1; j <= LOGN; j++)
//     {
//         for (int i = 1; i + (1 << j) - 1 <= n; i++)
//         {
//             st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
//         }
//     }

//     int ans = 0;
//     for (int i = 1; i < n; i++)
//     {
//         int left = i + 1;
//         int right = n;
//         int best = i;

//         while (left <= right)
//         {
//             int mid = (left + right) / 2;
//             int len = mid - (i + 1) + 1;
//             int k = Log2[len];

//             int max_h = max(st[i + 1][k], st[mid - (1 << k) + 1][k]);

//             if (max_h < data[i])
//             {
//                 best = mid;
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid - 1;
//             }
//         }

//         ans += (best - i);
//     }

//     cout << ans << endl;
// }

// signed main()
// {
//     int T = 1;
//     // cin >> T;
//     while (T--)
//     {
//         solve();
//     }
//     return 0;[]
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> data(n);

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    stack<int> stk;
    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 0;
        while (!stk.empty() && data[stk.top()] < data[i])
        {
            stk.pop();
        }

        if (!stk.empty())
        {
            ans += stk.top() - i - 1;
        }
        else
        {
            ans += (n - 1) - i;
        }

        stk.push(i);
    }

    cout << ans << endl;
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