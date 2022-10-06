#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    if (n != 1)
    {
        printf("robie_subtask_na_10_tylko\n");
        return 0;
    }

    char s[1'001];
    scanf("%s", s);
    vector<int> result;

    for (int length = 1; length <= m; ++length)
    {
        if (m % length != 0)
            continue;
        LOG("testing length %d\n", length);
        bool succ = 1;
        for (int start = 0; start < m && succ; start += length)
        {
            for (int i = start; i < start + length && succ; ++i)
            {
                LOG("letter at %d: %c, at %d: %c\n", i, s[i], i % length, s[i % length]);
                if (s[i] != s[i % length])
                    succ = 0;
            }
        }
        if (succ)
            result.push_back(length);
    }

    printf("%ld\n", result.size());
    for (int l : result)
        printf("%d ", l);
    printf("\n");
}

