#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int main()
{
    int n;
    scanf("%d", &n);
    n /= 10;
    n %= 10;
    printf("%d\n", n);
}
