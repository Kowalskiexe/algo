// doesn't work
#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef complex<int> P;
#define Y imag()
#define X real()
typedef long long ll;

int n;
vector<P> moves;

ll inline cross(const P& a, const P& b)
{
    return a.X * b.Y - a.Y * b.X;
}

// true if b is on the right in respect of a
bool inline angle_cmp(const P& a, const P& b)
{
    return cross(a, b) <= 0;
}

int main()
{
    scanf("%d", &n); 
    moves.resize(n * 2);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        moves[i] = {x, y};
    }

#if DEBUG
    for (int i = 0; i < n; ++i)
        LOG("%d %d\n", moves[i].X, moves[i].Y);
#endif

    ll best = 0;
    for (int i = 0; i < n; ++i)
    {
        P cur;
        for (int j = 0; j < n; ++j)
        {
            if (angle_cmp(moves[i], moves[j]))
                cur += moves[j];
        }
        best = max(best, (ll)norm(cur));
    }

    printf("%lld\n", best);
}
