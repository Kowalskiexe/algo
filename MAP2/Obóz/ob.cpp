#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<int> v;

int main()
{
    scanf("%d", &n);

    v.resize(n * 4);
    for (int i = 0; i < n * 4; ++i)
        scanf("%d", &v[i]);

    sort(v.begin(), v.end());

    ll out = 0;
    for (int i = 0; i < 4 * n; i += n)
        out += v[i + n - 1] - v[i];

    printf("%lld\n", out);
}
