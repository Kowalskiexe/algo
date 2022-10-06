#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char str[19];

int main() {
    scanf("%s", str);
    int n = strlen(str);
    int left = 0;
    for (int i = 0; i < n / 2; ++i)
        left += str[i] - '0';
    int right = 0;
    for (int i = n / 2; i < n; ++i)
        right += str[i] - '0';
    LOG("l: %d r: %d\n", left, right);
    if (left == right)
        printf("TAK\n");
    else
        printf("NIE\n");
}

