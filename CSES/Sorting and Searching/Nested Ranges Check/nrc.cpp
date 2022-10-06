#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
struct point
{
    int pos, id, open;
    point(int pos, int id, int open): pos(pos), id(id), open(open) {}
    bool operator<(const point& other) const
    {
        return pos < other.pos;
    }
};

vector<point> v;

int main()
{
    scanf("%d", &n);

    v.reserve(n);
    v.reserve(n * 2);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(a, i, 1);
        v.emplace_back(b, i, 0);
    }

    sort(v.begin(), v.end());

    vector<int> cont(n); // containes
    vector<int> conted(n); // is contained
    set<int> ids;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (v[i].open)
        {
            ids.insert(v[i].id);
        }
        else
        {
            conted[v[i].id] = 1;
            LOG("%d is contaied by ", v[i].id);
            ids.erase(v[i].id);
            for (int j : ids)
            {
                cont[j] = 1;
                LOG("%d, ", j);
            }
            LOG("\n");
        }
    }

    for (int i : cont)
        printf("%d ", i);
    printf("\n");
    for (int i : conted)
        printf("%d ", i);
    printf("\n");
}

