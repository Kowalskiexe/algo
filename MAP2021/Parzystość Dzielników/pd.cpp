#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

ll n;

int main()
{
    scanf("%lld", &n);
    if (n % 2 == 1)
        printf("0 1\n");
    else
    {
        int two = 0;
        while (n % 2 == 0)
        {
            two++;
            n /= 2;
        }
        printf("%d 1", two);
    }
}
