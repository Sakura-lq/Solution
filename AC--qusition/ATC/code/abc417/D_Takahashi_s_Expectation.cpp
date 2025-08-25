#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct Segment
{
    int l, r;      // 区间 [l, r)
    int slope;     // 斜率 (0 或 1)
    int intercept; // 截距
    Segment(int _l, int _r, int _slope, int _intercept) : l(_l), r(_r), slope(_slope), intercept(_intercept) {}
};

// 函数在 x 上的值
int f(const Segment &seg, int x)
{
    return seg.slope * x + seg.intercept;
}

// 合并连续的线性段（斜率和截距相同）
void mergeSegments(vector<Segment> &segs)
{
    vector<Segment> merged;
    for (auto &seg : segs)
    {
        if (!merged.empty() && merged.back().slope == seg.slope && merged.back().intercept == seg.intercept && merged.back().r == seg.l)
        {
            merged.back().r = seg.r;
        }
        else
        {
            merged.push_back(seg);
        }
    }
    segs = move(merged);
}

int INF = (int)1e15;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<tuple<int, int, int>> presents(N);
    for (int i = 0; i < N; i++)
    {
        int p, a, b;
        cin >> p >> a >> b;
        presents[i] = {p, a, b};
    }

    // 初始函数 f(x) = x, 定义一个大区间
    vector<Segment> func = {Segment(0, INF, 1, 0)};

    // 处理每个礼物，更新函数
    for (auto &[P, A, B] : presents)
    {
        vector<Segment> newFunc;

        for (auto &seg : func)
        {
            // seg 区间 [l,r), 线性函数 y = slope*x + intercept

            // 先判断区间切分点（P）
            if (P < seg.l)
            {
                // 全部 x > P，使用 mood < mood 转换规则 y = max(0, f(x)-B)
                // 先计算线性函数 f(x) = slope*x + intercept
                // 变换 y = f(x) - B，截断为 >=0
                int newSlope = seg.slope;
                int newIntercept = seg.intercept - B;

                // 找截断点 x0，使得 y=0，即 slope*x0 + intercept - B = 0
                // x0 = (B - intercept) / slope
                // 注意 slope 可能为0，要单独处理
                if (newSlope == 0)
                {
                    // y = const intercept - B, >=0 或 0
                    if (newIntercept >= 0)
                    {
                        newFunc.emplace_back(seg.l, seg.r, 0, newIntercept);
                    }
                    else
                    {
                        // 全区间都为0
                        newFunc.emplace_back(seg.l, seg.r, 0, 0);
                    }
                }
                else
                {
                    // slope = 1 or -1
                    double x0 = double(-newIntercept) / newSlope;
                    int ix0 = (int)ceil(x0);

                    // 分段讨论
                    if (ix0 <= seg.l)
                    {
                        // 全区间 >=0
                        newFunc.emplace_back(seg.l, seg.r, newSlope, newIntercept);
                    }
                    else if (ix0 >= seg.r)
                    {
                        // 全区间 <0，截断为0
                        newFunc.emplace_back(seg.l, seg.r, 0, 0);
                    }
                    else
                    {
                        // 分两段
                        newFunc.emplace_back(seg.l, ix0, 0, 0);
                        newFunc.emplace_back(ix0, seg.r, newSlope, newIntercept);
                    }
                }
            }
            else if (P >= seg.r - 1)
            {
                // 全部 x ≤ P，使用 mood ≥ mood 转换规则 y = f(x) + A
                int newSlope = seg.slope;
                int newIntercept = seg.intercept + A;
                newFunc.emplace_back(seg.l, seg.r, newSlope, newIntercept);
            }
            else
            {
                // 区间跨越 P，拆分为两段
                // 1. 左段 x ≤ P
                int leftL = seg.l;
                int leftR = P + 1; // 注意区间为左闭右开

                int newSlopeLeft = seg.slope;
                int newInterceptLeft = seg.intercept + A;
                newFunc.emplace_back(leftL, leftR, newSlopeLeft, newInterceptLeft);

                // 2. 右段 x > P
                int rightL = P + 1;
                int rightR = seg.r;

                int newSlopeRight = seg.slope;
                int newInterceptRight = seg.intercept - B;

                // 截断0逻辑同上
                if (newSlopeRight == 0)
                {
                    if (newInterceptRight >= 0)
                    {
                        newFunc.emplace_back(rightL, rightR, 0, newInterceptRight);
                    }
                    else
                    {
                        newFunc.emplace_back(rightL, rightR, 0, 0);
                    }
                }
                else
                {
                    double x0 = double(-newInterceptRight) / newSlopeRight;
                    int ix0 = (int)ceil(x0);
                    if (ix0 <= rightL)
                    {
                        newFunc.emplace_back(rightL, rightR, newSlopeRight, newInterceptRight);
                    }
                    else if (ix0 >= rightR)
                    {
                        newFunc.emplace_back(rightL, rightR, 0, 0);
                    }
                    else
                    {
                        newFunc.emplace_back(rightL, ix0, 0, 0);
                        newFunc.emplace_back(ix0, rightR, newSlopeRight, newInterceptRight);
                    }
                }
            }
        }
        // 合并相邻同类型区间
        mergeSegments(newFunc);
        func = move(newFunc);
    }

    int Q;
    cin >> Q;
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];

    // 查询函数，二分查找区间
    for (int x : queries)
    {
        int l = 0, r = (int)func.size() - 1, ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (func[mid].l <= x && x < func[mid].r)
            {
                ans = func[mid].slope * x + func[mid].intercept;
                break;
            }
            else if (func[mid].l > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (ans < 0)
            ans = 0; // 安全起见
        cout << ans << '\n';
    }
    return 0;
}
