#include <bits/stdc++.h>
using namespace std;

int M(int a, int b) { return a == b ? 1 : 0; }

struct Node
{
    int l, r;
    bool c0, c1;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<Node> stk;
    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
        stk.push_back({i, i, S[i] == '0', S[i] == '1'});

        while (stk.size() >= 2)
        {
            Node b = stk.back();
            stk.pop_back();
            Node a = stk.back();
            stk.pop_back();

            bool can0 = false, can1 = false;
            for (int x = 0; x <= 1; x++)
            {
                for (int y = 0; y <= 1; y++)
                {
                    if ((x == 0 && !a.c0) || (x == 1 && !a.c1))
                        continue;
                    if ((y == 0 && !b.c0) || (y == 1 && !b.c1))
                        continue;
                    int merged = M(x, y);
                    if (merged == 0)
                        can0 = true;
                    else
                        can1 = true;
                }
            }

            if (!can0 && !can1)
            {
                stk.push_back(a);
                stk.push_back(b);
                break;
            }
            else
            {
                stk.push_back({a.l, b.r, can0, can1});
            }
        }
        if (stk.back().c1)
        {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
