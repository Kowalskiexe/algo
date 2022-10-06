#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    int j = n % 10;
    n /= 10;
    int d = n % 10;
    n /= 10;
    int s = n;

    if (s <= d && d <= j)
        printf("TAK\n");
    else
        printf("NIE\n");
}
