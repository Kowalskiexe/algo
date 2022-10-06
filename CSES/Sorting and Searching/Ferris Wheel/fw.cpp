#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &p[i]);

    sort(p.begin(), p.end());

    int result = 0;
    for (int start = 0, end = p.size() - 1; start <= end;)
    {
        if (p[start] + p[end] <= x)
        {
            result++;
            start++;
            end--;
        }
        else
        {
            result++;
            end--;
        }
    }
    printf("%d\n", result);
}

