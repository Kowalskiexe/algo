#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, q;
vector<bool> raw;
vector<vector<bool>> vec;

int main()
{
    scanf("%d", &n);
    raw.resize(n);
    for (int i = 0; i < n; ++i)
    {
        char c;
        scanf(" %c", &c);
        if (c == 'B')
            raw[i] = true;
    }
    scanf("%d", &q);
#if DEBUG
    for (int i = 0; i < n; ++i)
        LOG("%d ", (int)raw[i]);
    LOG("\n");
#endif
    int start = 0;
    while (start < n)
    {
        vec.emplace_back(n);
        int id = vec.size() - 1;
        //vec[id].resize(n);

        bool type = raw[start];
        vec[id][start] = true;
        int count = 1;
        int i = start + 1;
        while (count < 4)
        {
            while (raw[i] == type && i < n)
                i++;
            if (i == n)
            {
                vec.pop_back();
                break;
            }
            else
                vec[id][i] = true;
            count++;
            type = !type;
        }

        start++;
    }
#if DEBUG
    LOG("processed:\n");
    for (auto u : vec)
    {
        for (bool i : u)
            LOG("%d ", (int)i);
        LOG("\n");
    }
#endif

    for (int i = 0; i < q; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        LOG("for %d %d: ", x, y);
        int out = INT_MAX;
        for (int i = 0; i < vec.size(); ++i)
        {
            if (vec[i][x - 1] && vec[i][y - 1])
            {
                // make faster
                int start = 0;
                while (!vec[i][start])
                    start++;
                int end = n - 1;
                while (!vec[i][end])
                    end--;
                out = min(out, end - start);
            }
        }
        if (out == INT_MAX)
            out = -1;
        printf("%d\n", out);
    }
}

