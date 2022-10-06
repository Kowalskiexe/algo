#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

vector<int> parents;

int find(int a)
{
    if (parents[a] == -1)
        return a;
    else

void unio(int a, int b)
{
}

int main()
{
    scanf("%d %d", &n, &m);
    parents.resize(n + 1);
    for (int i = 0; i < n + 1; ++i)
        parents[i] = -1;
}

