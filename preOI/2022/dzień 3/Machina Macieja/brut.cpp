#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<vector<int>> mat;

int n, m, k, l;

int sqmin(int x1, int y1, int x2, int y2) {
    int out = INT_MAX;
    for (int x = x1; x <= x2; x++)
        for (int y = y1; y <= y2; y++)
            out = min(out, mat[x][y]);
    return out;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &l);

    mat.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &mat[i][j]);

    for (int i = 1; i + k - 1 <= n; i++) {
        for (int  j = 1; j + l - 1 <= m; j++) {
            int mini = sqmin(i, j, i + k - 1, j + l - 1);
            printf("%d ", mini);
        }
        printf("\n");
    }
}

