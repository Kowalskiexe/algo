#include <bits/stdc++.h>
using namespace std;

int n;
multiset<int> t;

int main()
{
    scanf("%d", &n);

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        auto it = t.upper_bound(in);
        if (it == t.end())
        {
            count++;
            t.insert(in);
        }
        else
        {
            t.erase(it);
            t.insert(in);
        }
    }
    printf("%d\n", count);
}
