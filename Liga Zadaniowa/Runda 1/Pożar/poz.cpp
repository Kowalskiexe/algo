#include <bits/stdc++.h>

using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef pair<int, int> point;

int n, q;
vector<point> people;
struct ff;
vector<ff> firefighters;
int results[500'000];


vector<int> tree;
int R;

void inline insert(int index)
{
    int i = R + index - 1;
    while (i > 0)
    {
        tree[i]++;
        i /= 2;
    }
}

int inline _quary(int x, int a, int b, int ta, int tb)
{
    //LOG("\t\tta: %d\ttb: %d\ta: %d\tb: %d\tx: %d\n",
    //        ta, tb, a, b, x);
    if (ta <= a && tb >= b)
    {
        //LOG("\t\tret: a: %d b: %d v: %d\n", a, b, tree[x]);
        return tree[x];
    }
    
    int mid = (a + b) / 2;
    int out = 0;
    if (ta <= mid)
        // left
        out += _quary(x * 2, a, mid, ta, tb);
    if (tb > mid)
        // right
        out += _quary(x * 2 + 1, mid + 1, b, ta, tb); 
    return out;
}

int inline quary(int index)
{
    LOG("\tquary: %d\n", index);
    return _quary(1, 0, R, 0, index);
}

struct ff
{
    int x, y, num;
    ff(int x, int y, int num): x(x), y(y), num(num) {};
    
    bool operator<(const ff& other)
    {
        if (x == other.x)
            return y < other.y;
        else
            return x < other.x;
    }
};

int main()
{
    tree.resize(10'000'000);
    scanf("%d %d", &n, &q);
    LOG("%d %d\n", n, q);
    people.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        people.emplace_back(x - y, x + y);
    }
    sort(people.begin(), people.end());
#if DEBUG
    LOG("people sorted:\n");
    for (int i = 0; i < n; ++i)
        LOG("%d %d\n", people[i].first, people[i].second);
#endif

    firefighters.reserve(q);
    for (int i = 0; i < q; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        firefighters.emplace_back(x - y, x + y, i);
    }
    sort(firefighters.begin(), firefighters.end());
#if DEBUG
    LOG("firefighters sorted:\n");
    for (int i = 0; i < n; ++i)
        LOG("%d %d\n", firefighters[i].x, firefighters[i].y);
#endif


    R = 1;
    while (R < 4'000'000)
        R *= 2;
    LOG("R:%d\n", R);

    int pushed_p = 0;
    int pushed_f = 0;
    LOG("sweep:\n");
    for (int x = -2'000'000; x < 2'000'000; ++x)
    {
        //LOG("x: %d\n", x);
        while (people[pushed_p].first == x && pushed_p < n)
        {
            insert(people[pushed_p].second);
            LOG("\tadding at %d\n", people[pushed_p].second);
            pushed_p++;
        }
        
        while (firefighters[pushed_f].x == x && pushed_f < q)
        {
            int y = firefighters[pushed_f].y;
            int res = quary(y);
            LOG("\t%d %d FOUND: %d\n", firefighters[pushed_f].x, y, res);
            results[firefighters[pushed_f].num] = res;
            pushed_f++;
        }
    }

    for (int i = 0; i < q; ++i)
        printf("%d\n", results[i]);
}
