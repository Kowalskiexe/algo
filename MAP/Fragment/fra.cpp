#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char s[(int)1e6+1];
vector<int> pre;

int n, m;

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%s", s);

    pre.resize(n + 1);
    for (int i = 0; i < n; ++i)
    {
        pre[i + 1] = pre[i];
        if (s[i] == 'A')
            pre[i + 1]++;
    }

    for (int i = 0; i <= n; ++i)
        LOG("%d: %d\n", i, pre[i]);

    int result = INT_MAX;
    for (int i = 1; i <= n - m + 1; ++i)
    {
        int count = pre[i + m - 1] - pre[i - 1];
        int diff = abs(m - 2*count);
        LOG("%d %d count: %d, diff: %d\n", i, i + m - 1, count, diff);
        result = min(result, diff);
    }
    printf("%d\n", result);
}
