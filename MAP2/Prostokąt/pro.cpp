#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int main()
{
    vector<int> v(4);
    scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);
    sort(v.begin(), v.end());
    if (v[0] == v[1] && v[2] == v[3])
        printf("TAK\n");
    else
        printf("NIE\n");
}
