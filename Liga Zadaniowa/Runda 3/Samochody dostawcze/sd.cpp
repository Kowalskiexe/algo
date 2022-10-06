#include <bits/stdc++.h>

using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<int> h; // horizontal direction, go right
vector<int> v; // vertical direction, go up

int n;

int main()
{
    scanf("%d", &n);
    LOG("%d\n", n);

    h.resize(3e6L + 4);
    v.resize(3e6L + 4);
    LOG("s: %ld\n", h.size());
    for (int i = 0; i < n; ++i)
    {
        int r, w, t;
        scanf("%d %d %d", &r, &w, &t);
        w -= t;
        if (r == 1)
            h[w + 1e6]++;
        else
            v[w + 1e6]++;
    }

    int remove = 0;
    for (int i = 0; i <= 3e6L; ++i)
    {
        remove += min(h[i], v[i]);
    }

    printf("%d\n", remove);
}
