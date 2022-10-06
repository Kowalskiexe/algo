#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

typedef long long ll;
typedef unsigned long ul;

vector<int> odd;

int n, moves;

int main()
{
    scanf("%d %d", &n, &moves);

    odd.reserve(n / 2);

    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        if (in % 2 == 1)
            odd.push_back(i);
    }

    if (odd.size() % 2 == 1)
    {
        LOG("not even number of odd numbers\n");
        printf("0\n");
        return 0;
    }

    ll dist = 0;
    for (ul i = 0; i < odd.size(); i += 2)
    {
        dist += odd[i + 1] - odd[i] - 1;
    }

    if (dist > moves)
    {
        LOG("too few moves (need: %lld, has: %d)\n", dist, moves);
        printf("0\n");
        return 0;
    }

    int result = n - odd.size() / 2;
    printf("%d\n", result);
}
