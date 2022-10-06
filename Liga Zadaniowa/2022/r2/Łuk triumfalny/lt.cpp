#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
vector<vector<int>> adj;

vector<int> dp;

void dfs(int v, int p, int k) { // this is bad
    for (int u : adj[v])
        if (u != p)
            dfs(u, v, k);
    dp[v] = INT_MAX;
    int sum = 0;
    for (int u : adj[v])
        if (u != p)
            sum = dp[u] + 1;
    dp[v] = max(0, sum - k);
}

int check(int k) {
    LOG("check: %d\n", k);
    dp.clear();
    dp.resize(n + 1);
    dfs(1, 0, k);
    for (int i = 1; i <= n; i++)
        LOG("%d: %d\n", i, dp[i]);
    return dp[1];
}

int main() {
    scanf("%d", &n);

    adj.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int a = 0, b = n - 1;
    while (a <= b) {
        int mid = (a + b) / 2;
        int now = check(mid);
        int less = check(mid - 1);
        LOG("trying %d, now: %d less: %d\n", mid, now, less);
        if (now == 0 && less > 0) {
            LOG("solution %d\n", mid);
            return 0;
        }
        if (less == 0)
            b = mid;
        else
            a = mid + 1;
    }
}

