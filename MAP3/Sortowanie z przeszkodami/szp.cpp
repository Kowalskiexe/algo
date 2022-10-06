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
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        if (raw[i] == 'A')
            a[i] = true;
        else
            s.push_back(raw[i]);
    }
    sort(s.begin(), s.end());

    int last = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i])
            printf("A");
        else
        {
            printf("%c", s[last]);
            last++;
        }
    }
    printf("\n");
}

