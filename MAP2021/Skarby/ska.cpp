#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

map<int, ll> proX, proY;
map<pair<int, int>, int> z;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        z[make_pair(x, y)] = v;
        proX[x] += v;
        proY[y] += v;
        LOG("profit na x[%d]: %lld, profit na y[%d]: %lld\n", x, proX[x], y, proY[y]);
    }

    ll maxX = -1, maxY = -1;
    int xid = -1;
    for (const auto& [key, value] : proX)
    {
        if (maxX < value)
        {
            maxX = value;
            xid = key;
        }
    }

    for (const auto& [key, value] : proY)
    {
        maxY = max(maxY, value - z[make_pair(xid, key)]);
    }

    printf("%lld\n", maxX + maxY);
}

