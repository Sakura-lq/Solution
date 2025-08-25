#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<long long> pre_sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre_sum[i] = pre_sum[i - 1] + p[i];
    }

    deque<int> dq;
    dq.push_back(0);

    long long ans = LLONG_MIN;

    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && dq.front() < i - m)
        {
            dq.pop_front();
        }

        ans = max(ans, pre_sum[i] - pre_sum[dq.front()]);

        while (!dq.empty() && pre_sum[dq.back()] >= pre_sum[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << ans << "\n";

    return 0;
}
