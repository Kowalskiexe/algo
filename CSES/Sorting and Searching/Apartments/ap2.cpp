#include <bits/stdc++.h>

using namespace std;

int main()
{
    int appl_count, apar_count, k;
    scanf("%d %d %d", &appl_count, &apar_count, &k);

    vector<int> appl;
    appl.resize(appl_count);
    for (int i = 0; i < appl_count; ++i)
        scanf("%d", &appl[i]);

    vector<int> apar;
    apar.resize(apar_count);
    for (int i = 0; i < apar_count; ++i)
        scanf("%d", &apar[i]);

    sort(appl.begin(), appl.end());
    sort(apar.begin(), apar.end());

    int result = 0;
    for (int i = 0, j = 0; i < appl_count && j < apar_count;)
    {
        if (apar[j] >= appl[i] - k && apar[j] <= appl[i] + k)
        {
            i++;
            j++;
            result++;
        }
        else if (apar[j] > appl[i] + k)
            i++;
        else
            j++;
    }
    printf("%d\n", result);
}

