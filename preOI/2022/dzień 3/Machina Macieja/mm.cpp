#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, m, k, l;

constexpr int log2(ll n) {
    int out = 0;
    while (n != 0) {
        out++;
        n /= 2;
    }
    return out;
}

vector<vector<int>> mat;
vector<vector<ll>> pref;

int**** st;

int query(int x1, int y1, int x2, int y2) {
    int lenx = x2 - x1 + 1;
    int kx = log2(lenx);
    int leny = y2 - y1 + 1;
    int ky = log2(leny);

    int R1 = min(st[kx][x1][ky][y1], st[kx][x1][ky][y2+1-(1 << ky)]);
    int R2 = min(st[kx][x2 + 1 - (1 << kx)][ky][y1], st[kx][x2 + 1 - (1 << kx)][ky][y2+1-(1 << ky)]);
    return min(R1, R2);
}

ll presum(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 = 1];
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &l);

    mat.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            scanf("%d", &mat[i][j]);
    }

    pref.resize(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] + pref[i - 1][j - 1];
        }
    }
    
    //  [jr][ir][jc][ic]
    st = new int[1 + log2(n)][n][1 + log2(m)][m];

    for (int ir = 1; ir <= n; ir++) {
        for (int ic = 1; ic <= m; ic++)
            st[0][ir][0][ic] = mat[ir][ic];
        for (int jc = 1; jc <= log2(m); jc++)
            for (int ic = 1; ic + (1 << jc) <= m; ic++)
                st[0][ir][jc][ic] = min(mat[0][ir][jc - 1][ic],
                        mat[0][ir][jc - 1][ic + (1 << (jc - 1))]);
    }
    for (int jr = 1; jr <= log2(n); jr++)
        for (int ir = 1; ir <= n; ir++)
            for (jr = 0; jr <= log2(m); jr++)
                for (int ic = 1; ic <= m; ic++)
                    st[jr][ir][jc][ic] = min(st[jr - 1][ir][jc][ic],
                            st[jr - 1][ir + (1 << (jc - 1))][ic]);

    for (int r = 1; r <= n - k + 1; r++) {
        for (int c = 1; c <= m - k + 1; c++) {
            int mini = query(r, c, r + k - 1, c + k - 1);
            ll sum = presum(r, c, r + k - 1, c + k - 1);
            printf("%lld ", sum - mini * k * k);
        }
        printf("\n");
    }
}

