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

struct Op {
    char sign;
    int a, b;
    Op(char sign, int a, int b): sign(sign), a(a), b(b) {}
};

vector<int> get_shorest_path(
    const vector<vector<int>> &adj,
    int src,
    int dst,
    pair<int, int> banned_edge = {-1, -1}
    // order doesn't matter
    // {-1, -1} means that no edge is banned
) {
    vector<int> parent(adj.size() + 1, -1);
    vector<bool> visited(adj.size() + 1, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = src;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (c == dst) {
            vector<int> path;
            path.push_back(c);
            while (c != parent[c]) {
                c = parent[c];
                path.push_back(c);
            }
            reverse(path.begin(), path.end());
            return path;
        }
        for (int u : adj[c]) {
            // skip banned endge
            if ((c == banned_edge.first || c == banned_edge.second)
                && (u == banned_edge.first || u == banned_edge.second)) {
                continue;
            }

            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                parent[u] = c;
            }
        }
    }
    // no path found
    return vector<int>();
}

vector<Op> add_missing_edge(
    vector<vector<int>> &adj,
    int a,
    int b
) {
    vector<Op> ops;

    vector<int> path = get_shorest_path(adj, a, b);
    for (int i = 2; i < (int)path.size(); i++) {
        ops.emplace_back('+', a, path[i]);
    }
    for (int i = 2; i < (int)path.size() - 1; i++) {
        ops.emplace_back('-', a, path[i]);
    }
    adj[a].push_back(b);
    adj[b].push_back(a);

    return ops;
}

vector<Op> remove_edge(
    vector<vector<int>> &adj,
    int a,
    int b
) {
    vector<Op> ops;

    auto path = get_shorest_path(adj, a, b, {a, b});
    pair<int, int> last = {a, b};
    for (int i = 1; i < (int)path.size() - 2; i++) {
        ops.emplace_back('+', path[i], b);
        ops.emplace_back('-', last.first, last.second);
        last = {path[i], b};
    }
    ops.emplace_back('-', last.first, last.second);

    // update adj
    auto it = find(adj[a].begin(), adj[a].end(), b);
    adj[a].erase(it);
    it = find(adj[b].begin(), adj[b].end(), a);
    adj[b].erase(it);

    return ops;
}

void test_get_shortest_path();

int main() {
#if DEBUG
    test_get_shortest_path();
#endif
    int n;
    scanf("%d", &n);
    vector<vector<int>> adj(n + 1);
    int m;
    scanf("%d", &m);
    set<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        e.emplace(min(a, b), max(a, b));
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int target_m;
    scanf("%d", &target_m);
    set<pair<int, int>> target_e;
    for (int i = 0; i < target_m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        target_e.emplace(min(a, b), max(a, b));
    }
    // get missing edges
    vector<pair<int, int>> missing;
    for (pair p : target_e) {
        if (e.count(p) == 0) {
            LOG("missing %d %d\n", p.first, p.second);
            missing.push_back(p);
        }
    }
    vector<Op> all_ops;

    // add missing edges
    for (pair p : missing) {
        auto ops = add_missing_edge(adj, p.first, p.second);
        all_ops.insert(
            all_ops.end(),
            make_move_iterator(ops.begin()),
            make_move_iterator(ops.end())
        );
    }
    // get bad edges
    vector<pair<int, int>> bad;
    for (pair p : e) {
        if (target_e.count(p) == 0) {
            LOG("%d %d to be removed\n", p.first, p.second);
            bad.push_back(p);
        }
    }
    // remove bad edges
    for (pair p : bad) {
        auto ops = remove_edge(adj, p.first, p.second);
        all_ops.insert(
            all_ops.end(),
            make_move_iterator(ops.begin()),
            make_move_iterator(ops.end())
        );
    }

    printf("%ld\n", all_ops.size());
    for (Op op : all_ops) {
        printf("%c %d %d\n", op.sign, op.a, op.b);
    }
}

void test_get_shortest_path() {
    vector<vector<int>> adj(7); // 6 nodes
    auto add_edge = [&](int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    };
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(4, 5);
    add_edge(5, 6);
    add_edge(6, 1);
    auto solution = get_shorest_path(adj, 1, 5);
    assert(solution == vector<int>({1, 6, 5}));
    solution = get_shorest_path(adj, 1, 5, {6, 1});
    assert(solution == vector<int>({1, 2, 3, 4, 5}));
    LOG("test_get_shortest_path passed\n");
}
