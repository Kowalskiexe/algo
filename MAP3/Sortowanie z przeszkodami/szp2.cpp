#include <bits/stdc++.h>
using namespace std;

vector<char> s;
vector<bool> a;
char raw[100001];

int main()
{
    scanf("%s", raw);
    int n = strlen(raw);

    s.reserve(n);
    int stop = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (raw[i] == 'A')
            stop = min(i, stop);
        else
            s.push_back(raw[i]);
    }
    sort(s.begin(), s.end());

    for (int i = 0; i < (int)s.size(); ++i)
        if (i == stop)
            break;
        else
            printf("%c", s[i]);
    printf("A\n");
}

