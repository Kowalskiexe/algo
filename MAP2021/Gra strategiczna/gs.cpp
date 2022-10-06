#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<ll> prex;
vector<ll> prey;

vector<pair<int, int>> rawx;
vector<pair<int, int>> rawy;

ll dx(int x)
{
    return rawx[x].first * x - prex[x-1] + prex[n - 1] - prex[x] - rawx[x].first * (n - x - 1);
}

ll dy(int y)
{
    return rawy[y].first * y - prey[y-1] + prey[n - 1] - prey[y] - rawy[y].first * (n - y - 1);
}

struct City
{
    int x, y, id;
    City(int x, int y, int id): x(x), y(y), id(id) {}
    ll d() const {
        return dx(x) + dy(y);
    }
    bool operator<(const City& other) const
    {
        return this->d() < other.d();
    }
};

vector<City> c;

int main()
{
    scanf("%d", &n);

    rawx.reserve(n);
    rawy.reserve(n);
    c.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        rawx.emplace_back(x, i);
        rawy.emplace_back(y, i);
        c.emplace_back(x, y, i);
    }

    sort(rawx.begin(), rawx.end());
    sort(rawy.begin(), rawy.end());
    for (int i = 0; i < n; ++i)
        c[rawx[i].second].x = i;
    for (int i = 0; i < n; ++i)
        c[rawy[i].second].y = i;

    prex.resize(n);
    prey.resize(n);

    prex[0] = rawx[0].first;
    prey[0] = rawy[0].first;

    for (int i = 1; i < n; ++i)
        prex[i] = prex[i - 1] + rawx[i].first;
    for (int i = 1; i < n; ++i)
        prey[i] = prey[i - 1] + rawy[i].first;

    sort(c.begin(), c.end());
    printf("%lld\n", (*--c.end()).d());
}

