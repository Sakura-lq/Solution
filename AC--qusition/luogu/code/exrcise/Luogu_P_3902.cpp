#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> lis;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end())
        {
            lis.push_back(a[i]);
        }
        else
        {
            *it = a[i];
        }
    }

    cout << n - (int)lis.size() << "\n";
    return 0;
}
