#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n;
char in[(int)1e6 + 1];

ll s, su, sus;

int main()
{
    scanf("%d %s", &n, in);

    for (int i = 0; i < n; ++i)
    {
        if (in[i] == 'S')
        {
            s++;
            sus += su;
        }
        else if (in[i] == 'U')
        {
            su += s;
        }
    }

    printf("%lld\n", sus);
}
