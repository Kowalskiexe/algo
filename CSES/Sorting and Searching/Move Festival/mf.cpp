#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> movies;
int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        movies.emplace_back(end, start);
    }
    
    sort(movies.begin(), movies.end());

    int count = 1;
    int last = 0;
    for (int i = 1; i < movies.size(); ++i)
    {
       if (movies[last].first <= movies[i].second)
       {
           count++;
           last = i;
       }
    }
    printf("%d\n", count);
}
