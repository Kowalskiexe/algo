#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<set<int>> dv;

set<int> get_dv(int n)
{
    set<int> out;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            out.insert(i);
            out.insert(n / i);
        }
    }
    return out;
}


int main()
{
    scanf("%d", &n);

    dv.resize(n);
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        dv[i] = get_dv(in);
    }
#if DEBUG
    for (int i = 0; i < n; ++i)
    {
        LOG("%d: ", i);
        for (int j : dv[i])
            LOG("%d ", j);
        LOG("\n");
    }
#endif
    vector<bool> calced(n);
    for (int i = 0; i < n; ++i)
    {
        int curr = *(--dv[i].end());
        LOG("calcing %d\n", curr);
        if (calced[i])
        {
            LOG("for %d found earlier\n", curr);
            LOG("RESULT: ");
            printf("1 ");
            LOG("\n\n");
            continue;
        }
        auto it = (--dv[i].end());
        while (it != dv[i].begin())
        {
            LOG("\tdiv: %d\n", *it);
            vector<int> found;
            found.reserve(3);
            found.push_back(i);
            for (int j = i + 1; j < n; ++j)
            {
                auto id = dv[j].find(*it);
                if (id != dv[j].end())
                {
                    LOG("\tfound %d at %d\n", *it, j);
                    found.push_back(j);
                    if (found.size() == 3)
                        break;
                }
            }
#if DEBUG
            LOG("\tfor %d div: %d, found %ld items:\n", curr, *it, found.size());
            for (int j : found)
                LOG("\t%d\n", j);
#endif
            if (found.size() == 3)
            {
                LOG("for %d div found: %d\n", curr, *it);
                LOG("RESULT: ");
                printf("1 ");
                LOG("\n\n");
                for (int id : found)
                    calced[id] = true;
                break;
            }
            it--;
        }
        if (it == dv[i].begin())
        {
            LOG("for %d not found\n", curr);
            LOG("RESULT: ");
            printf("0 ");
            LOG("\n\n");
        }
    }
}

