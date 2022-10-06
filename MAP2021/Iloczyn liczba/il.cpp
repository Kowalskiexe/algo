#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<int> v;

int main()
{
    v.resize(3);
    for (int i = 0; i < 3; ++i)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    printf("%d\n", v[0] * v[1]);
}
