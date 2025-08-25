#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
int t[105];
int n, m;

void update(int idx, int delta)
{
    while (idx <= n)
    {
        t[idx] += delta;
        idx += idx & -idx;
    }
}

int query(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += t[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int find_kth(int k)
{
    int low = 1, high = n, res = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (query(mid) >= k)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

void solve()
{
    cin >> n >> m;

    int data[n + 1];
    for (int i = 1; i <= n; i++)
    {
        data[i] = i;
        update(i, 1);
    }

    int cur = 0;

    for (int i = 0; i < n; i++)
    {
        int mod = n - i;
        cur = (cur + m) % mod == 0 ? mod : (cur + m) % mod;

        int pos = find_kth(cur);
        cout << data[pos] << " ";

        update(pos, -1);

        cur = query(pos);
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