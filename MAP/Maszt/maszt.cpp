#include <bits/stdc++.h>

int n, q;
int t[1000001];

int main()
{
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; ++i)
    {
        int num = 0;
        for (int i = 0; i < 5; ++i)
        {
            int in;
            scanf("%d", &in);
            num *= 10;
            num += in;
        }
        t[i] = num;
    }

    int cur = 0;
    for (int i = 0; i < q; ++i)
    {
        int inq;
        scanf("%d", &inq);
        cut = 1;
        while (cur / cut != inq / cut)
        {
            cut *= 10;
        }
    }

