#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
int main()
{
    scanf("%d", &n);
    printf("%d\n", (n - 1) / 5);
}
