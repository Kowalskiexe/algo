#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<int> arr;
vector<int> dep;
int n;

int main()
{
    scanf("%d", &n);

    arr.reserve(n);
    dep.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a, d;
        scanf("%d %d", &a, &d);
        arr.push_back(a);
        dep.push_back(d);
    }

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    unsigned long at = 0, dt = 0;
    int res = 0, now = 0;
    while (at < arr.size())
    {
        if (arr[at] == dep[dt])
        {
            at++;
            dt++;
        }
        else if (arr[at] < dep[dt])
        {
            now++;
            LOG("arrival %d now: %d\n", arr[at], now);
            if (now > res)
                res = now;
            at++;
        }
        else
        {
            now--;
            LOG("departure %d now: %d\n", dep[dt], now);
            dt++;
        }
    }
    printf("%d\n", res);
}
