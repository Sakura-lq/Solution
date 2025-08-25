#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

enum class QueryType {
    MAX,   
    MIN     
};

template<typename T, QueryType Type>
class STTable {
private:
    vector<vector<T>> st;  
    vector<int> logTable;  
    int n;                 
    int maxLevel;          

    void precomputeLog() {
        logTable.resize(n + 1);
        logTable[1] = 0;
        for (int i = 2; i <= n; ++i) {
            logTable[i] = logTable[i / 2] + 1;
        }
        maxLevel = logTable[n] + 1;
    }

    function<T(const T&, const T&)> getOperator() {
        if (Type == QueryType::MAX) {
            return [](const T& a, const T& b) { return max(a, b); };
        } else {
            return [](const T& a, const T& b) { return min(a, b); };
        }
    }

public:
    STTable(const vector<T>& data) {
        n = data.size() - 1; 
        precomputeLog();

        st.resize(n + 1, vector<T>(maxLevel + 1));
        for (int i = 1; i <= n; ++i) {
            st[i][0] = data[i];
        }

        auto op = getOperator();

        for (int j = 1; j <= maxLevel; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int x, int y) {
        int length = y - x + 1;
        int k = logTable[length];
        auto op = getOperator();
        return op(st[x][k], st[y - (1 << k) + 1][k]);
    }
};

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int>qu(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> qu[i];
    }
    STTable<int, QueryType::MIN>min_q(qu);
    STTable<int, QueryType::MAX>max_q(qu);

    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        cout << max_q.query(l, r) - min_q.query(l, r) << endl;
    }
    return ;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}