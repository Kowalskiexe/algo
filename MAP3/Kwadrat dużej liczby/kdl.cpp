#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main()
{
    scanf("%lld", &n);

    for (int i = 0; i < n - 1; ++i)
        printf("9");
    printf("8");
    for (int i = 0; i < n - 1; ++i)
        printf("0");
    printf("1\n");
}
