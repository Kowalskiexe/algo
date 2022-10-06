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
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    int result = 0;
    for (int i = 0; i < n - 1; ++i)
        result = max(result, abs(v[i] - v[i + 1]));
    printf("%d\n", result);
}
