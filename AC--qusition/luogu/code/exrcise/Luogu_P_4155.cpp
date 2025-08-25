#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;
const int LIMIT = 21;

int powerVal;
int lineArr[MAXN << 1][3];
int stjump[MAXN << 1][LIMIT];
int ansArr[MAXN];
int n, m;

int logv[MAXN * 2 + 5];

void preLog(int limit)
{
    logv[1] = 0;
    for (int i = 2; i <= limit; i++)
    {
        logv[i] = logv[i / 2] + 1;
    }
}

void build()
{
    for (int i = 1; i <= n; i++)
    {
        if (lineArr[i][1] > lineArr[i][2])
        {
            lineArr[i][2] += m;
        }
    }
    vector<array<int, 3>> tmp;
    tmp.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        tmp.push_back({lineArr[i][0], lineArr[i][1], lineArr[i][2]});
    }
    sort(tmp.begin(), tmp.end(), [](const array<int, 3> &a, const array<int, 3> &b)
         { return a[1] < b[1]; });
    for (int i = 0; i < n; i++)
    {
        lineArr[i + 1][0] = tmp[i][0];
        lineArr[i + 1][1] = tmp[i][1];
        lineArr[i + 1][2] = tmp[i][2];
    }

    for (int i = 1; i <= n; i++)
    {
        lineArr[i + n][0] = lineArr[i][0];
        lineArr[i + n][1] = lineArr[i][1] + m;
        lineArr[i + n][2] = lineArr[i][2] + m;
    }
    int e = n << 1;
    for (int i = 1, arrive = 1; i <= e; i++)
    {
        while (arrive + 1 <= e && lineArr[arrive + 1][1] <= lineArr[i][2])
        {
            arrive++;
        }
        stjump[i][0] = arrive;
    }
    for (int p = 1; p <= powerVal; p++)
    {
        for (int i = 1; i <= e; i++)
        {
            stjump[i][p] = stjump[stjump[i][p - 1]][p - 1];
        }
    }
}

int jump_func(int i)
{
    int aim = lineArr[i][1] + m;
    int cur = i, next;
    int cnt = 0;
    for (int p = powerVal; p >= 0; p--)
    {
        next = stjump[cur][p];
        if (next != 0 && lineArr[next][2] < aim)
        {
            cnt += 1 << p;
            cur = next;
        }
    }
    return cnt + 2;
}

void compute()
{
    preLog(n << 1);
    powerVal = logv[n << 1];
    build();
    for (int i = 1; i <= n; i++)
    {
        ansArr[lineArr[i][0]] = jump_func(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        lineArr[i][0] = i;
        cin >> lineArr[i][1] >> lineArr[i][2];
    }
    compute();
    cout << ansArr[1];
    for (int i = 2; i <= n; i++)
    {
        cout << " " << ansArr[i];
    }
    cout << "\n";
    return 0;
}
