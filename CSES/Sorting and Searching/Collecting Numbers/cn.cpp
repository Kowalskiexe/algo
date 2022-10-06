#include <bits/stdc++.h>

int pos[200'002];
int n;

int main()
{
    scanf("%d", &n);

    int out = 0;
    for (int i = 1; i <= n; ++i)
    {
        int in;
        scanf("%d", &in);
        pos[in] = i;
        if (pos[in - 1] == 0)
            out++;
    }
    printf("%d\n", out);
}
