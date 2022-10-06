#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m, z, d;

vector<vector<pair<int, int>>> adj;

int main() {
    scanf("%d%d", &n, &m);
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, s;
        scanf("%d%d%d", &a, &b, &s)

