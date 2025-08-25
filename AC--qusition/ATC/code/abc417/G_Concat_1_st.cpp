#include <bits/stdc++.h>
using namespace std;

int n, k;
long long x;
vector<string> s;
vector<string> all;

void dfs(string &cur, int depth)
{
    if (depth == k)
    {
        all.push_back(cur);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        string old = cur;
        cur += s[i];
        dfs(cur, depth + 1);
        cur = old;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> x;
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    string cur = "";
    dfs(cur, 0);

    sort(all.begin(), all.end());

    cout << all[x - 1] << "\n";

    return 0;
}
