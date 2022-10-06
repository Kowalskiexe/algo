#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int t;

int bigger_than(const vector<int>& p, int n)
{
    // how many bigger than 0
    auto it = lower_bound(p.begin(), p.end(), n, greater<int>());
    int count = distance(p.begin(), it);
    return count;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        LOG("N: %d\n", n);
        int strike = 0;
        int one_count = 0;
        vector<int> p;
        for (int i = 0; i < n; ++i)
        {
            char in;
            scanf(" %c", &in);
            LOG("%c", in);
            if (in == '1')
            {
                if (one_count == 0)
                {
                    if (strike != 0)
                        p.push_back(strike);
                }
                else
                {
                    if (strike == 0)
                        ;
                    else if (strike == 1)
                        p.push_back(1);
                    else if (strike % 2 == 0)
                    {
                        p.push_back(strike / 2);
                        p.push_back(strike / 2);
                    }
                    else
                    {
                        p.push_back(strike / 2 + 1);
                        p.push_back(strike / 2);
                    }
                }
                strike = 0;
                one_count++;
            }
            else
                strike++;
        }
        LOG("\n");
        if (strike > 0 && one_count > 0)
            p.push_back(strike);
        sort(p.begin(), p.end(), greater<int>());
        LOG("p:");
        for (int i : p)
            LOG(" %d", i);
        LOG("\n");
        LOG("bigger than 1: %d\n", bigger_than(p, 1));
        int taken = 0;
        for (int i = 1, b = 10;; ++i)
        {
            b = bigger_than(p, i - 1) - i;
            LOG("b: %d\n", b);
            if (b <= 0)
                break;
            taken += b;
        }
        if (one_count == 0)
            printf("0\n");
        else
            printf("%d\n", one_count + taken);
        LOG("\n");
    }
}

