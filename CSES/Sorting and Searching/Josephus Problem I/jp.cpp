#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<int> t;

int main()
{
    scanf("%d", &n);
    t.reserve(2 * n);
    for (int i = 1; i <= n; ++i)
        t.push_back(i);

    int i = 1, r = 0;
    t.push_back(t[0]);
    while (r < n)
    {
        printf("%d ", t[i]);
        r++;
        t.push_back(t[i + 1]);
        i += 2;
    }
    printf("\n");
}
