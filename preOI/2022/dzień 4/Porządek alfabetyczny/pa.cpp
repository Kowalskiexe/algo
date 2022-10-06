#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

const int maxN = 500, maxL = 20'000;
int n, l;

char s[maxN][maxL + 1];

bool cmp(int a, int b, int i, int j) {
    for (int k = a; k <= b; k++) {
        if (s[i][k] < s[j][k])
            return true;
        if (s[i][k] > s[j][k])
            return false;
    }
    return false;
}

bool is_proper(int a, int b) {
    for (int i = 1; i < n; i++) {
        bool c = cmp(a, b, i - 1, i);
        if (!c)
            return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &l);

    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    // search begin
    int begin = -1;
    int a = 0, b = l - 1;
    while (a <= b) {
        int mid = (a + b) / 2;
        LOG("\ttrying %d\n", mid);
        bool atmid = is_proper(mid, l - 1);
        bool afmid = is_proper(mid + 1, l - 1);
        if (atmid && !afmid) {
            LOG("left found %d\n", mid);
            begin = mid;
            break;
        }
        if (atmid)
            a = mid + 1;
        else
            b = mid;
    }

    // search end
    int end = -1;
    a = begin, b = l - 1;
    while (a <= b) {
        int mid = (a + b) / 2;
        LOG("\ttrying %d\n", mid);
        bool atmid = is_proper(begin, mid);
        bool bemid = is_proper(begin, mid - 1);
        if (atmid && !bemid) {
            LOG("right found %d\n", mid);
            end = mid;
            break;
        }
        if (atmid)
            b = mid;
        else
            a = mid + 1;
    }

    printf("%d %d\n", begin + 1, end + 1);
}

