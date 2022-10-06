#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int x, y;
int main()
{
    scanf("%d %d", &x, &y);

    if (x <= 2 && y >= 2)
        printf("1\n");
    else
        printf("0\n");
}
