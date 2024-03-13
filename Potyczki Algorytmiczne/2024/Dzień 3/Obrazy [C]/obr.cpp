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

int main() {
    int h, w;
    scanf("%d%d", &h, &w);
    int n;
    scanf("%d", &n);
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &d[i]);
    for (int i = 0; i < n; i++)
        LOG("%d ", d[i]);
    LOG("\n");
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, -1));
    for (int y = 0; y <= h; y++)
        dp[y][0] = 0;
    for (int x = 0; x <= w; x++)
        dp[0][x] = 0;
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            dp[y][x] = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (x - d[i] >= 0
                    && y - d[i] >= 0
                    && d[i] <= x
                    && dp[y][x - d[i]] != -1
                    && dp[y - d[i]][d[i]] != -1
                ) {
                    dp[y][x] = min(
                        dp[y][x],
                        dp[y][x - d[i]] + dp[y - d[i]][d[i]] + 1
                    );
                }
                if (x - d[i] >= 0
                    && y - d[i] >= 0
                    && d[i] <= h
                    && dp[y - d[i]][x] != -1
                    && dp[d[i]][x - d[i]] != -1
                ) {
                    dp[y][x] = min(
                        dp[y][x],
                        dp[y - d[i]][x] + dp[d[i]][x - d[i]] + 1
                    );
                }
            }
            if (dp[y][x] == INT_MAX)
                dp[y][x] = -1;
        }
    }
    for (int y = 0; y <= h; y++) {
        for (int x = 0; x <= w; x++)
            LOG("%2d ", dp[y][x]);
        LOG("\n");
    }
    printf("%d\n", dp[h][w]);
}
