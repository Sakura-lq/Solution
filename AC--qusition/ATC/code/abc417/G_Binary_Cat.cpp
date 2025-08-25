#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAXQ = 500000 + 5;
int Q;
int L[MAXQ], R[MAXQ];
__int128 X[MAXQ];    // 因为X最大10^18，int64够用，long long就够了
long long Xll[MAXQ]; // 读入X用long long存储

__int128 len[MAXQ];

long long query(int cur, __int128 pos)
{
    while (cur >= 2)
    {
        if (pos <= len[L[cur]])
        {
            cur = L[cur];
        }
        else
        {
            pos -= len[L[cur]];
            cur = R[cur];
        }
    }
    return (cur == 0 ? 0 : 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;

    len[0] = 1;
    len[1] = 1;

    for (int i = 1; i <= Q; i++)
    {
        cin >> L[i] >> R[i] >> Xll[i];
        X[i] = Xll[i];
        len[i + 1] = len[L[i]] + len[R[i]];
        if (len[i + 1] > 1000000000000000000LL)
            len[i + 1] = 1000000000000000000LL;
    }

    for (int i = 1; i <= Q; i++)
    {
        cout << query(i + 1, X[i]) << '\n';
    }

    return 0;
}
