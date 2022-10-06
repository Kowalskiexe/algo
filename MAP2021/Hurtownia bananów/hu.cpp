#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int q;
ll tax;

int main()
{
    scanf("%d", &q);
    priority_queue<pair<int, int>> banana;
    for (int i = 0; i < q; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        banana.push({i, x});
        int outed = 0;
        int last = 0;
        while (outed < y)
        {
            outed += banana.top().second;
            last = banana.top().first;
            LOG("outing %d from %d, stayed %d, tax: %d\n", banana.top().second, last, i - last, (1 + i - last) * (i - last) / 2);
            tax += (1 + i - last) * (i - last) / 2;
            banana.pop();
        }
        if (outed > y)
        {
            banana.push({last, outed - y});
            LOG("returned: %d, %d, t: %d\n", outed - y, i - last, (1 + i - last) / 2);
            tax -= (1 + i - last) * (i - last) / 2;
        }
    }
    printf("%lld\n", tax);
}

