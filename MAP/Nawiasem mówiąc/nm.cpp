#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long ul;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, q;

struct point
{
    int id, pos;
    bool open;
    point(int id, int pos, bool open): id(id), pos(pos), open(open) {}
    bool inline operator<(const point& other)
    {
        return this->pos < other.pos;
    }
};

vector<point> points;
vector<pair<int, int>> plat;
vector<char> out;

int main()
{
    scanf("%d %d", &n, &q);

    points.reserve(q * 2);
    out.resize(n + 1);
    for (int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        points.emplace_back(i, a, true);
        points.emplace_back(i, b, false);
        plat.emplace_back(a, b);

        out[a] = '(';
        out[b] = ')';
    }

    sort(points.begin(), points.end());

    set<int> open;
    for (ul i = 0; i < points.size(); ++i)
    {
        if (points[i].open)
        {
            open.insert(points[i].id);
        }
        else
        {
            // take down
            open.erase(points[i].id);
            for (int j : open)
            {
                if (plat[j].first > plat[points[i].id].first)
                {
                    printf("NIE\n");
                    return 0;
                }
            }
        }
    }
    if (!open.empty())
    {
        printf("NIE\n");
        return 0;
    }

    printf("TAK\n");
    for (ul i = 1; i < out.size(); ++i)
        printf("%c", out[i]);
    printf("\n");
}
