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

    v.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int in;
        scanf("%d", &in);
        v[in] = i;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", v[i]);
    printf("\n");
}
