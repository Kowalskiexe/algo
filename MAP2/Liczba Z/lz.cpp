#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int q;
ll m;

vector<ll> tree;
int R;

void inline update(int index)
{
    do
    {
        index /= 2;
        tree[index] = tree[index * 2] * tree[index * 2 + 1] % m;
    }
    while (index > 0);
}

void inline insert(int n)
{
    int index = n + R - 1;
    tree[index] = n;
    update(index);
}

void inline remove(int n)
{
    int index = n + R - 1;
    tree[index] = 1;
    update(index);
}

int main()
{
    scanf("%d %lld", &q, &m);
    R = 1;
    while (R < 1e6)
        R *= 2;

    tree.resize(R * 2 + 1);
    for (int i = 0; i < R * 2 + 1; ++i)
        tree[i] = 1;

    for (int i = 0; i < q; ++i)
    {
        char t;
        int p;
        scanf(" %c %d", &t, &p);
        if (t == '*')
            insert(p);
        else
            remove(p);
        printf("%lld\n", tree[1]);
    }
}

