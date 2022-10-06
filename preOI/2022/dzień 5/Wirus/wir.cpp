#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, x1;
vector<int> g;
vector<vector<int>> adj;

int main() {
    scanf("%d%d", &n, &x1);
    g.resize(n - 2);
    for (int i = 0; i < n - 2; i++)
        scanf("%d", &g[i]);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

