#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

// brute :3

int n, m, k;

vector<vector<bool>> area;

bool check(int x, int y, int w, int h) {
    int x2 = x + w - 1;
    int y2 = y + h - 1;
    for (int i = x; i <= x2; i++) {
        for (int j = y; j <= y2; j++) {
            if (area[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    area.resize(n, vector<bool>(m));
    for (int i = 0; i < k; i++) {
        int obsx, obsy;
        scanf("%d%d", &obsx, &obsy);
        obsx--; obsy--;
        area[obsx][obsy] = true;
    }

    ll result = 0;
    for (int w = 1; w <= n; w++)
        for (int h = 1; h <= m; h++)
            for (int x = 0; x <= n - w; x++)
                for (int y = 0; y <= m - h; y++)
                    if (check(x, y, w, h))
                        result++;
    printf("%lld\n", result);
}

