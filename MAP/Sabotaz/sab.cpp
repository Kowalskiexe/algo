#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> L;
vector<int> P;

int main()
{
    scanf("%d", &n);
    
    L.reserve(n);
    P.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        char typ;
        int rozmiar;
        scanf(" %c %d", &typ, &rozmiar);

        if (typ == 'L')
            L.push_back(rozmiar);
        else
            P.push_back(rozmiar);
    }

    sort(L.begin(), L.end());
    sort(P.begin(), P.end());

    int pairs = 0;

    vector<bool> vL(L.size());
    vector<bool> vP(P.size());
    for (unsigned long i = 0, j = 0; i < L.size() && j < P.size();)
    {
        if (L[i] == P[j] + 1 || L[i] == P[j] - 1)
        {
            vL[i] = true;
            vP[j] = true;
            pairs++;
            i++; j++;
        }
        else
        {
            if (L[i] >= P[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }

    int last = -1;
    for (unsigned long i = 0; i < L.size(); ++i)
    {
        if (!vL[i])
        {
            if (last == L[i])
            {
                pairs++;
                last = -1;
            }
            else
                last = L[i];
        }
    }
    last = -1;
    for (unsigned long i = 0; i < P.size(); ++i)
    {
        if (!vP[i])
        {
            if (last == P[i])
            {
                pairs++;
                last = -1;
            }
            else
                last = P[i];
        }
    }
    printf("%d\n", pairs);
}
