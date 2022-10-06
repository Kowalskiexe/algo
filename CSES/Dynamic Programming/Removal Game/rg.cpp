#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> v;
int n;

bool inline solve(int i, int j)
{
    if (i + 1 == j)
        return v[i] >= v[j];

}

int main()
{
    scanf("%d", &n);
    
    v.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

}
