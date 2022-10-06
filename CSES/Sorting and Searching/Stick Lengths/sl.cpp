#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

int main()
{
    scanf("%d", &n);
    v.resize(n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    sort(v.begin(), v.end());

    int midval = v[n / 2];

    long long res = 0;
    for (int i = 0; i < n; ++i)
    {
        int d = midval - v[i];
        if (d < 0)
            d = -d;
        res += d;
    }

    printf("%lld\n", res);
}
