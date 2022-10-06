#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<int> v;
vector<int> p;
int n;

int result = 1;

void inline permutate(int, int);
void inline permutate(int z, int x, int y)
{
    LOG("x: %d (%d) y: %d (%d) z: %d (%d) ", x, v[x], y, v[y], z, v[z]);
    bool proper = true;
    if (z < x)
    {
        // left
        LOG("left ");
        for (int i = z + 1; i < x; ++i)
        {
            if (v[i] > y - z + 1)
            {
                proper = false;
                break;
            }
        }

        if (proper)
        {
            result++;
            x = z;
        }
    }
    else
    {
        // right
        LOG("right ");
        for (int i = y + 1; i < z; ++i)
        {
            if (v[i] > z - x + 1)
            {
                proper = false;
                break;
            }
        }

        if (proper)
        {
            result++;
            y = z;
        }
    }
    if (y - x + 1 == n) return;
    if (proper)
    {
        LOG("proper\n");
        int pos = p[y - x + 2];
        permutate(pos, x, y);
    }
    else
    {
        LOG("not proper\n");
        if (z < x)
            x = z;
        else
            y = z;
        if (p[v[z] + 1] < x)
            x = p[v[z] + 1];
        else
            y = p[v[z] + 1];

        permutate(x, y);
    }
}

void inline permutate(int x, int y)
{
    LOG("x: %d (%d) y: %d (%d) ", x, v[x], y, v[y]);
    bool proper = true;
    for (int i = x; i <= y; ++i)
    {
        if (v[i] > y - x + 1)
        {
            proper = false; 
            break;
        }
    }
    if (proper)
    {
        LOG("proper\n");
        result++;
        if (y - x + 1 == n) return;
        int pos = p[y - x + 2];
        permutate(pos, x, y);
    }
    else
    {
        LOG("not proper\n");
        if (y - x + 1 == n) return;
        int pos = p[y - x + 2];
        if (pos < x)
            x = pos;
        else
            y = pos;
        permutate(x, y);
    }
}

int main()
{
    scanf("%d", &n);

    p.resize(n + 1);
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
        p[v[i]] = i;
    } 
#if DEBUG
    for (int i = 0; i < n; ++i)
        LOG("%d ", v[i]);
    LOG("\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d ", p[i]);
    LOG("\n");
#endif
    permutate(min(p[1], p[2]), max(p[1], p[2]));
    LOG("\n");
    printf("%d\n", result);
}
