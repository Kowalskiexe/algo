#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<pair<ll, ll>> sort_by_mat;
vector<pair<ll, ll>> sort_by_inf;
int main()
{
    scanf("%d", &n);

    sort_by_mat.reserve(n);
    sort_by_inf.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int ina, inb;
        scanf("%d %d", &ina, &inb);
        
        sort_by_mat.emplace_back(ina * 1e9 + inb, i);
        sort_by_inf.emplace_back(ina + inb * 1e9, i);
    }

    sort(sort_by_mat.begin(), sort_by_mat.end());
    sort(sort_by_inf.begin(), sort_by_inf.end());

    int place_mat = 1;
    int place_inf = 1;
    ll last_mat = -1;
    ll last_inf = -1;
    int pm = 1;
    int pi = 1;
    for (int i = 0; i < n; ++i)
    {
        if (sort_by_mat[i].second == 0)
            place_mat = pm;
        if (sort_by_inf[i].second == 0)
            place_inf = pi;
        if (last_mat != sort_by_mat[i].first)
            pm++;
        last_mat = sort_by_mat[i].first;
        if (last_inf != sort_by_inf[i].first)
            pi++;
        last_inf = sort_by_inf[i].first;
    }
    place_mat = n - place_mat + 1;
    place_inf = n - place_inf + 1;

    if (place_mat <= place_inf)
        printf("%d\n1000000000 1\n", place_mat);
    else
        printf("%d\n1 1000000000\n", place_inf);
}
        
