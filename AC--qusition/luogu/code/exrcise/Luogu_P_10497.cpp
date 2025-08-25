#include <iostream>
using namespace std;

int t[8010];
int n;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    for (; k <= n; k += lowbit(k))
    {
        t[k] += v;
    }
}

int query(int k)
{
    int sum = 0;
    for (; k > 0; k -= lowbit(k))
    {
        sum += t[k];
    }
    return sum;
}

int find_kth(int pos)
{
    int low = 1, high = n;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (query(mid) >= pos)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    cin >> n;
    int data[8010];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> data[i];
    }
    for (int i = 1; i <= n; i++)
    {
        update(i, 1);
    }

    int ans[8010];

    if (n >= 2)
    {
        int k = data[n - 2] + 1;
        int pos = find_kth(k);
        ans[n - 1] = pos;
        update(pos, -1);
    }

    for (int i = n - 2; i >= 1; i--)
    {
        int k = data[i - 1] + 1;
        int pos = find_kth(k);
        ans[i] = pos;
        update(pos, -1);
    }

    ans[0] = find_kth(1);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}