#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<int> t;
vector< vector<int> > st;
int n, q;

int log2(int n) {
    int out = 0;
    while (n != 0) {
        out++;
        n /= 2;
    }
    return out - 1;
}

int query(int a, int b) {
    int d = b - a + 1;
    int k = log2(d);
    return min(st[k][a], st[k][b - (1 << k) + 1]);
}

int main() {
    scanf("%d", &n);
    t.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    st.resize(1 + log2(n), vector<int>(n));
    for (int i = 0; i < n; i++)
        st[0][i] = t[i];
    for (int j = 1; j <= log2(n); j++)
        for (int i = 0; i < n; i++)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << j) - 1]);

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(a, b));
    }
}

