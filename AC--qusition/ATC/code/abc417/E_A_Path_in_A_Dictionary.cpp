#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            sort(g[i].begin(), g[i].end());
        }

        vector<vector<int>> bp(n + 1);
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, greater<>> q;
        bp[x] = {x};
        q.push({bp[x], x});

        while (!q.empty())
        {
            auto [p, u] = q.top();
            q.pop();

            if (u == y)
            {
                for (int i = 0; i < (int)p.size(); i++)
                {
                    cout << p[i];
                    if (i + 1 < (int)p.size())
                    {
                        cout << ' ';
                    }
                }
                cout << endl;
                break;
            }

            if (p != bp[u])
            {
                continue;
            }   

            for (int w : g[u])
            {
                if (find(p.begin(), p.end(), w) == p.end())
                {
                    vector<int> np = p;
                    np.push_back(w);
                    if (bp[w].empty() || np < bp[w])
                    {
                        bp[w] = np;
                        q.push({np, w});
                    }
                }
            }
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
