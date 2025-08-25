#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int MAXN = 200000 + 10;

int n, Q;

// 组合数预处理
int fact[MAXN], invFact[MAXN];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void initComb(int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invFact[n] = qpow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

int C(int n, int m)
{
    if (m > n || m < 0)
        return 0;
    return fact[n] * invFact[m] % MOD * invFact[n - m] % MOD;
}

// 斐波那契数列预处理 fib[0]=0, fib[1]=1
int fib[MAXN];
void initFib(int n)
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
}

// 计算长度为 L，放 k 个不相邻1的方案数
// 公式 C(L-k+1, k)
int ways_fixed(int L, int k)
{
    if (k > (L + 1) / 2)
        return 0; // 不可能放那么多不相邻的1
    return C(L - k + 1, k);
}

// 计算长度为 L 的无约束区间方案数，等于斐波那契 fib[L+2]
int ways_unconstrained(int L)
{
    if (L < 0)
        return 1; // 空区间
    return fib[L + 2];
}

// 维护约束点，key=pos，value=coffee_count (-1 表示无约束)
map<int, int> constraints;

// 维护区间方案数乘积
int totalWays = 1;

// 模逆
int mod_inv(int x)
{
    return qpow(x, MOD - 2);
}

// 计算区间 [l+1, r] 的方案数，区间长度 L = r - l
// 约束点为 constraints[l], constraints[r]
// coffee counts: cL = constraints[l], cR = constraints[r]
// 注意 l < r
int calcInterval(int l, int r)
{
    int L = r - l;
    int cL = constraints[l];
    int cR = constraints[r];
    if (cL == -1 || cR == -1)
    {
        // 无约束区间
        return ways_unconstrained(L);
    }
    else
    {
        // 有约束区间，咖啡数固定
        int k = cR - cL;
        if (k < 0 || k > L)
            return 0; // 不可能
        return ways_fixed(L, k);
    }
}

// 维护区间乘积，需要能快速更新
// 保存约束点位置，和每个区间方案数
// 我们用 constraints 的相邻点决定区间
// 维护一个辅助 map intervalWays: key = left endpoint, value = ways of [left+1, right]
// 当修改约束点时，需要更新左右区间的方案数和 totalWays

map<int, int> intervalWays;

void addInterval(int l, int r)
{
    int w = calcInterval(l, r);
    intervalWays[l] = w;
    totalWays = totalWays * w % MOD;
}

void removeInterval(int l)
{
    // 移除以 l 为左端点的区间
    int w = intervalWays[l];
    totalWays = totalWays * mod_inv(w) % MOD;
    intervalWays.erase(l);
}

void updateInterval(int l, int r)
{
    // 更新区间[l,r]方案数，先移除旧区间（如果存在），再加入新区间
    if (intervalWays.count(l))
        removeInterval(l);
    addInterval(l, r);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> Q;

    initComb(n + 10);
    initFib(n + 10);

    // 初始化约束点
    // 为方便处理，加入边界点
    // 0 位置约束为0咖啡数
    // n 位置约束为-1（无约束）
    constraints[0] = 0;
    constraints[n] = -1;

    // 计算初始区间方案数
    addInterval(0, n);

    for (int _ = 0; _ < Q; _++)
    {
        int x, y;
        cin >> x >> y;

        // 更新约束点 x
        // 若 y == -1 表示删除约束
        // 否则添加/修改约束

        // 先找到 x 的左邻点和右邻点
        auto it_right = constraints.lower_bound(x);
        if (it_right == constraints.end() || it_right->first != x)
        {
            // x 不在约束点中，插入
            // 先找到左邻
            auto it_left = prev(it_right);
            int l = it_left->first;
            int r = it_right->first;

            // 删除区间 [l,r]
            removeInterval(l);
            // 插入点 x
            constraints[x] = y;
            // 插入区间 [l,x] 和 [x,r]
            addInterval(l, x);
            addInterval(x, r);
        }
        else
        {
            // x 已经存在约束点
            int old_y = it_right->second;
            if (old_y == y)
            {
                // 没有变化，输出结果继续
                cout << totalWays << endl;
                continue;
            }
            // 找左右区间
            auto it_left = prev(it_right);
            auto it_next = next(it_right);

            int l = it_left->first;
            int r = it_next->first;

            // 删除旧区间 [l,x] 和 [x,r]
            removeInterval(l);
            removeInterval(x);

            // 修改约束值
            constraints[x] = y;

            // 添加新区间 [l,x] 和 [x,r]
            addInterval(l, x);
            addInterval(x, r);
        }

        cout << totalWays << endl;
    }

    return 0;
}
