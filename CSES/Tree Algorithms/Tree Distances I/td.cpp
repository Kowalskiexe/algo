#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;

vector<vector<int>> adj;

vector<int> maxLength1;

void dfs(int s, int e) {
    for (int u : adj[s]) {
        if (u == e) continue;
        dfs(u, s);
        maxLength1[s] = max(maxLength1[s], maxLength1[u] + 1);
    }
}


int main() {
    scanf("%d", &n);
    adj.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    maxLength1.resize(n + 1);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        LOG("%d: %d\n", i, maxLength1[i]);
}

