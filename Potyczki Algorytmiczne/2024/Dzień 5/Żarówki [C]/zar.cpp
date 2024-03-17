#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#define DOUT cout
#else
#define LOG(...)
#define DOUT if(0) cout
#endif

void dfs(
    const vector<vector<int>> &adj,
    int x,
    vector<bool> &visited,
    vector<int> &preorder
) {
    visited[x] = true;
    preorder.push_back(x); 
    for (int u : adj[x]) {
        if (!visited[u])
            dfs(adj, u, visited, preorder);
    }
}

struct Component {
    vector<int> vertices;
    vector<bool> arragement;
    vector<pair<int, int>> edges;
    int get_idx(int v) {
        for (int i = 0; i < (int)vertices.size(); i++) {
            if (vertices[i] == v) {
                return i;
            }
        }
        return -1;
    }
    void adjust_edges() {
        for (auto &e : edges) {
            e.first = get_idx(e.first);
            e.second = get_idx(e.second);
        }
    }
};


void _brute(
    const Component &c,
    vector<bool> &curr_arr,
    set<vector<bool>> &poss_arrs
) {
    poss_arrs.insert(curr_arr);
    for (auto e : c.edges) {
        int a = e.first;
        int b = e.second;
        if (curr_arr[a] != curr_arr[b])
            continue;
        curr_arr[a] = !curr_arr[a];
        curr_arr[b] = !curr_arr[b];
        if (poss_arrs.count(curr_arr) == 0)
            _brute(c, curr_arr, poss_arrs);
        curr_arr[a] = !curr_arr[a];
        curr_arr[b] = !curr_arr[b];
    }
}

set<vector<bool>> brute(const Component &c) {
    vector<bool> arr = c.arragement;
    set<vector<bool>> out;
    _brute(c, arr, out);
    return out;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // get components
    vector<Component> components;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.emplace_back();
            dfs(adj, i, visited, components.back().vertices);
        } 
    }
    for (auto &c : components) {
        c.arragement.reserve(c.vertices.size());
        for (int v : c.vertices)
            c.arragement.push_back(arr[v] == 1);
        for (int v : c.vertices)
            LOG("%d ", v);
        LOG("\n");
        for (int a : c.arragement)
            LOG("%d ", a);
        LOG("\n");
        for (int v : c.vertices) {
            for (int u : adj[v]) {
                if (u < v) {
                    c.edges.emplace_back(u, v);
                    LOG("%d %d\n", u, v);
                }
            } 
        }
        c.adjust_edges();
        LOG("\n");
    }
    
    ll result = 1;
    for (const auto &c : components) {
        for (int v : c.vertices)
             LOG("%d ", v);
        LOG("\n");
        auto solutions = brute(c);
        LOG("%ld\n", solutions.size());
        for (auto arr : solutions) {
            for (bool v : arr)
                LOG("%d ", v);
            LOG("\n");
        }
        result *= solutions.size();
        LOG("\n");
    }
    printf("%lld\n", result);
}
