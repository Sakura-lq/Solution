#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

struct Pt
{
    int x, y;
};

int gd(int a, int b)
{
    return b == 0 ? a : gd(b, a % b);
}

pair<int, int> sl(const Pt &a, const Pt &b)
{
    int dy = b.y - a.y;
    int dx = b.x - a.x;
    if (dx == 0)
    {
        return {1, 0}; 
    }
    if (dy == 0)
    {
        return {0, 1};
    }
    int g = gd(abs(dy), abs(dx));
    dy /= g;
    dx /= g;
    if (dx < 0)
    {
        dx = -dx;
        dy = -dy;
    }
    return {dy, dx};
}

void solve()
{
    int n;
    cin >> n;
    vector<Pt> ps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i].x >> ps[i].y;
    }

    map<pair<int, int>, vector<pair<int, int>>> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair<int, int> s = sl(ps[i], ps[j]);
            mp[s].emplace_back(i, j);
        }
    }

    set<array<int, 4>> st;
    vector<bool> used(n);

    for (auto &e : mp)
    {
        vector<pair<int, int>> &vl = e.second;
        int m = (int)vl.size();

        fill(used.begin(), used.end(), false);

        for (int i = 0; i < m; i++)
        {
            int a = vl[i].first;
            int b = vl[i].second;

            used[a] = true;
            used[b] = true;

            for (int j = i + 1; j < m; j++)
            {
                int c = vl[j].first;
                int d = vl[j].second;

                if (used[c] || used[d])
                {
                    continue;
                }

                vector<Pt> q = {ps[a], ps[b], ps[c], ps[d]};
                vector<int> id = {a, b, c, d};

                double cx = 0;
                double cy = 0;
                for (auto &p : q)
                {
                    cx += p.x;
                    cy += p.y;
                }
                cx /= 4.0;
                cy /= 4.0;

                vector<int> od = {0, 1, 2, 3};
                sort(od.begin(), od.end(), [&](int i1, int i2)
                     {
                    double a1 = atan2(q[i1].y - cy, q[i1].x - cx);
                    double a2 = atan2(q[i2].y - cy, q[i2].x - cx);
                    return a1 < a2; });

                array<int, 4> ar;
                for (int k = 0; k < 4; k++)
                {
                    ar[k] = id[od[k]];
                }
                sort(ar.begin(), ar.end());
                st.insert(ar);
            }

            used[a] = false;
            used[b] = false;
        }
    }

    cout << (int)st.size() << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
