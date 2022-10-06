#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<pair<int, int>> v;

int main()
{
    scanf("%d", &n);

    v.reserve(n * 2);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v.emplace_back(x, -1);
        v.emplace_back(y, 1);
    }

    sort(v.begin(), v.end());

    int m = 0;
    int curr = 0;
    int out = 0;
    for (int i = 0; i < n * 2; ++i)
    {
        curr -= v[i].second;
        if (curr > m)
        {
            m = curr;
            out = v[i].first;
        }
    }

    printf("%d\n", out);
}

