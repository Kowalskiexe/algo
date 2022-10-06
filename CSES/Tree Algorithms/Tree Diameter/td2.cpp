#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<vector<int>> adj;

vector<int> toLeaf;
vector<int> maxLength;
void dfs(int s, int e) {
    for (int u : adj[s]) {
        if (u == e) continue;
        dfs(u, s);
        toLeaf[s] = max(toLeaf[s], toLeaf[u] + 1);
    }
    if (adj[s].size() == 1) {
        if (s == 1)
            LOG("1 first\n");
        maxLength[s] = toLeaf[s];
    } else if (adj[s].size() == 2 && s != 1) {
        if (adj[s][0] == e)
            maxLength[s] = toLeaf[adj[s][1]] + 1;
        else
            maxLength[s] = toLeaf[adj[s][0]] + 1;
    } else {
        int max1 = -1, max2 = -1;
        for (int u : adj[s]) {
            if (u == e) continue;
            if (s == 1)
                LOG("u: %d, %d\n", u, toLeaf[u]);
            if (toLeaf[u] > max1) {
                max2 = max1;
                max1 = toLeaf[u];
            } else if (toLeaf[u] > max2)
                max2 = toLeaf[u];
        }
        if (s == 1)
            LOG("max1: %d max2: %d\n", max1, max2);
        maxLength[s] = max1 + max2 + 2;
    }
}

int main() {
    scanf("%d", &n);
    
    if (n == 1)
    {
        printf("0\n");
        return 0;
    }

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    toLeaf.resize(n + 1);
    maxLength.resize(n + 1);
    dfs(1, 0);

    LOG("toLeaf\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d: %d\n", i, toLeaf[i]);
    LOG("maxLength\n");
    for (int i = 1; i <= n; ++i)
        LOG("%d: %d\n", i, maxLength[i]);

    int result = -1;
    for (int i = 1; i <= n; ++i)
        result = max(result, maxLength[i]);
    printf("%d\n", result);
}

