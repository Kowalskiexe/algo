#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    sort(v.begin(), v.end());

    int out = 1;
    int last = v[n - 1];
    k--;
    for (int i = n - 2; i >= 0; --i)
    {
        if (last != v[i] && k <= 0)
            break;
        out++;
        k--;
        last = v[i];
    }
    printf("%d\n", out);
}

