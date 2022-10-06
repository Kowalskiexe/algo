#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
int R;
vector<int> t;
vector<int> v;

void update_t(int idx)
{
    while (idx > 1)
    {
        idx /= 2;
        t[idx] = t[idx * 2] + t[idx * 2 + 1];
    }
}

void insert(int val)
{
    int idx = val + R - 1;
    t[idx] = 1;
    update_t(idx);
}

void remove(int v)
{
    int idx = v + R - 1;
    t[idx] = 0;
    update_t(idx);
}

int nth(int n)
{
    //LOG("%dth\n", n);
    int left = 0;
    int idx = 1;
    while (idx < R)
    {
        //LOG("\tL: %d, idx: %d, t: %d\n", left, idx, t[idx]);
        if (n <= left + t[idx * 2])
        {
            // left
            //LOG("\tleft\n");
            idx *= 2;
        }
        else
        {
            // right
            //LOG("\tright\n");
            left += t[idx * 2];
            idx = idx * 2 + 1;
        }
    }
    return idx - R + 1;
}

double median()
{
    int count = t[1];
    if (count % 2 == 0)
    {
        double left = nth(count / 2);
        double right = nth(count / 2 + 1);
        return (left + right) / 2;
    }
    else
    {
        return nth(count / 2 + 1);
    }
}

// assumes the tree is prepared
ll f()
{
    int x = t[1];
    double y = median();
    return x + 2 * y;
}


int main()
{
    scanf("%d", &n);
    R = 1;
    while (R < n)
        R *= 2;
    t.resize(R * 2);

    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    LOG("N:%d\n", n);
    for (int i : v)
        LOG("%d ", i);
    LOG("\n");

    /*
    //insert(1);
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    for (int i = 0; i < R * 2; ++i)
        if (i >= R)
            LOG("%d - %d: %d\n", i, i - R + 1, t[i]);
        else
            LOG("%d: %d\n", i, t[i]);
    LOG("nth: %d\n", nth(1));
    LOG("nth: %d\n", nth(2));
    LOG("nth: %d\n", nth(3));
    LOG("nth: %d\n", nth(4));
    LOG("media: %f\n", median());
    */

    ll max_f = -1;
    int count_f = 0;
    for (int len = 1; len <= n; ++len)
    {
        LOG("len: %d\n", len);
        for (int i = 0; i < len; ++i) // init cater
        {
            LOG("init: %d\n", v[i]);
            insert(v[i]);
        }
        LOG("%d inserted\n", t[1]);
        LOG("median: %f\n", median());
        ll tf = f(); // tmp f
        LOG("f: %lld\n", tf);
        if (max_f == tf)
            count_f++;
        else if (tf > max_f)
        {
            max_f = tf;
            count_f = 1;
        }
        for (int s = 1; s + len - 1 < n; ++s) // cater
        {
            LOG("rem %d add %d\n", v[s - 1], v[s + len - 1]);
            remove(v[s - 1]);
            insert(v[s + len - 1]);
            LOG("median: %f\n", median());
            ll tf = f(); // tmp f
            LOG("f: %lld\n", tf);
            if (max_f == tf)
                count_f++;
            else if (tf > max_f)
            {
                max_f = tf;
                count_f = 1;
            }
        }
        for (int i = n - len; i < n; ++i) // clear
            remove(v[i]);
    }
    printf("%lld %d\n", max_f, count_f);
}

