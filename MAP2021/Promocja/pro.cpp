#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, k;
vector<int> v;
vector<ll> pre;
vector<ll> dp;

vector<vector<bool>> f(int n, int k)
{
    vector<vector<bool>> wyn;
    vector<bool> tym;
    int k2 = k;
    int last = k,akt=k, kon = n;
    for(int i =0; i < n; i++){
        if(k2>0){
            tym.push_back(true);
            k2--;
        }else{
            tym.push_back(false);
        }
    }
    wyn.push_back(tym);

    if(n==k){
        return wyn;
    } 

    while( true ){

        if(last == akt){
            last--;
        }
        tym[akt]=!tym[akt];
        tym[akt-1]=!tym[akt-1];
        akt++;
        wyn.push_back(tym);
        if(akt==kon){
            kon--;
            if(last == 0){
                return wyn;
            }else{
                akt = last;
            }
        }

    }

}

int main()
{
    scanf("%d %d", &n, &k);
    LOG("n: %d k: %d\n", n, k);
#if DEBUG
    auto a = f(n - 1, k - 1);
    for (auto u : a)
    {
        for (bool w : u)
            LOG("%d ", (int)w);
        LOG("\n");
    }
#endif
    v.resize(n * 3);
    for (int i = 0; i < n * 3; ++i)
        scanf("%d", &v[i]);

    pre.resize(n * 3);
    pre[0] = v[0];
    for (int i = 1; i < n * 3; ++i)
        pre[i] = pre[i - 1] + v[i];

#if DEBUG
    LOG("pre:\n");
    for (int i = 0; i < n * 3; ++i)
        LOG("%lld ", pre[i]);
    LOG("\nv:\n");
    for (int i = 0; i < n * 3; ++i)
        LOG("%d ", v[i]);
    LOG("\n");
#endif

    dp.resize(n * 3);
    auto o = f(n - 1, k - 1);
    LOG("O: %ld\n", o.size());
    for (int i = n; i < n * 3; ++i)
    {
        ll sum = pre[i - 1] - pre[i - n];
        LOG("%d: %lld - %lld sum: %lld\n", i, pre[i - 1], pre[i - n], sum);
        dp[i] = sum;
        for (auto row : o)
        {
            ll add = v[i];
            LOG("%lld\n", add);
            for (int j = 0; j < n - 1; ++j)
            {
                if (row[j])
                {
                    LOG("%d\n", v[i - j - 1]);
                    add += v[i - j - 1];
                }
            }
            LOG("dp: %lld add: %lld\n", dp[i], add);
            dp[i] = max(dp[i], add);
        }
    }
#if DEBUG
    LOG("dp:\n");
    for (int i = 0; i < n * 3; ++i)
        LOG("%lld\n", dp[i]);
    LOG("\n");
#endif
    printf("%lld\n", dp[n * 3- 1]);
}

