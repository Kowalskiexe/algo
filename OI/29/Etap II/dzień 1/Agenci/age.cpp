// Maciej Kowalski
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, k, start;

vector<vector<int>> adj;
vector<ll> dp;

void dfs(int x, int p) {
    for (int u : adj[x])
        if (u != p)
            dfs(u, x);
    ll v = 0;
    for (int u : adj[x])
        if (u != p)
            v += dp[u];

    dp[x] = v + 2 * (adj[x].size() - 1);
}

int find_end(int x, int p, int d = 0) {
    if (adj[x].size() == 1) {
        LOG("found %d\n", x);
        return d;
    }
    int mt = -1;
    int t = -1;
    for (int u : adj[x]) {
        if (u == p) continue;
        if (dp[u] > mt) {
            t = u;
            mt = dp[u];
        }
    }
    return find_end(t, x, d + 1);
}

vector<int> ag;

vector<bool> is_ag;
vector<bool> vis;
int get_d(int x, int p, int& o, int d = 0) {
    LOG("\tgd %d %d\n", x, p);
    vis[x] = true;
    if (is_ag[x]) {
        o = x;
        LOG("\tfound %d\n", x);
        return d;
    }
    for (int u : adj[x]) {
        if (u != p)
            return get_d(u, x, o, d + 1);
    }
    return 0;
}

int get_unvis(int x) {
    for (int u : adj[x])
        if (!vis[u])
            return u;
    LOG("error %d\n", x);
    return -1;
}

int main() {
    scanf("%d%d", &n, &k);

    ag.resize(k);
    for (int i = 0; i < k; i++)
        scanf("%d", &ag[i]);

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (k == 1) {
        LOG("subtask4\n");
        start = ag[0];

        dp.resize(n + 1);
        dfs(start, -1);
        dp[start] += 2;
        
        for (int i = 1; i <= n; i++)
            LOG("%d: %lld\n", i, dp[i]);

        int d = find_end(start, -1);
        int result = dp[start] - d;
        printf("%d\n", result);
    } else {
        LOG("subtask6\n");
        int end1 = -1, end2;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() == 1) {
                if (end1 == -1)
                    end1 = i;
                else {
                    end2 = i;
                    break;
                }
            }
        }
        LOG("end1: %d end2: %d\n", end1, end2);
        is_ag.resize(n + 1);
        for (int i = 0; i < k; i++)
            is_ag[ag[i]] = true;
        LOG("is_ag\n");
        for (int i = 1; i <= n; i++)
            LOG("%d: %d\n", i, (int)is_ag[i]);
        vis.resize(n + 1);
        int p1, g;
        LOG("\td1\n");
        int d1 = get_d(end1, -1, p1);
        LOG("\tb1\n");
        int b1 = get_d(get_unvis(p1), p1, g);
        int p2;
        LOG("\td2\n");
        int d2 = get_d(end2, -1, p2);
        LOG("\tb2\n");
        int b2 = get_d(get_unvis(p2), p2, g);
        LOG("d1: %d b1: %d d2: %d b2: %d\n", d1, b1, d2, b2);
        int result = n - k;
        if (d1 == 0 || d2 == 0)
            ;
        else
            result += min(b1, b2);
        printf("%d\n", result);
    }
}

