#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int pos[200'002];
int t[200'002];
int n, m;
int main()
{
    scanf("%d %d", &n, &m);

    int now = 0;
    for (int i = 1; i <= n; ++i)
    {
        int in;
        scanf("%d", &in);
        t[i] = in;
        pos[in] = i;
        if (pos[in - 1] == 0)
            now++;
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int diff = t[b] - t[a];
        bool a_pro0 = pos[t[a] - 1] < pos[t[a]];
        bool a_con0 = pos[t[a]] < pos[t[a] + 1];
        bool b_pro0 = pos[t[b] - 1] < pos[t[b]];
        bool b_con0 = pos[t[b]] < pos[t[b] + 1];
        int tmp = pos[t[a]];
        pos[t[a]] = pos[t[b]];
        pos[t[b]] = tmp;
        tmp = t[a];
        t[a] = t[b];
        t[b] = tmp;
        bool b_pro1 = pos[t[b] - 1] < pos[t[b]];
        bool b_con1 = pos[t[b]] < pos[t[b] + 1];
        bool a_pro1 = pos[t[a] - 1] < pos[t[a]];
        bool a_con1 = pos[t[a]] < pos[t[a] + 1];
        if (a_pro0 && !b_pro1)
            now++;
        if (!a_pro0 && b_pro1)
            now--;
        if (a_con0 && !b_con1)
            now++;
        if (!a_con0 && b_con1)
            now--;
        if (b_pro0 && !a_pro1 && diff != 1)
            now++;
        if (!b_pro0 && a_pro1 && diff != 1)
            now--;
        if (b_con0 && !a_con1 && diff != -1)
            now++;
        if (!b_con0 && a_con1 && diff != -1)
            now--;
        printf("%d\n", now);
    }
}
