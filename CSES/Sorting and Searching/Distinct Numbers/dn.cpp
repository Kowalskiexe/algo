#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
    scanf("%d", &n);
    vector<int> t;
    t.resize(n);

    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        t[i] = in;
    }

    sort(t.begin(), t.end());

    int distinct = 1;
    int last = t[0];
    for (int i = 1; i < n; ++i)
    {
        if (last != t[i])
            distinct++;
        last = t[i];
    }
    printf("%d\n", distinct);
}

