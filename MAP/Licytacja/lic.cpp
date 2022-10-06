#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);

    bool ns_dec = false;
    int last_value = 0;

    for (int i = 0; i < n; ++i)
    {
        int num;
        string let;
        cin >> num >> let;
        int value = num * 10;
        if (let == "C")
            value += 1;
        else if(let == "D")
            value += 2;
        else if (let == "H")
            value += 3;
        else if (let == "S")
            value += 4;
        else if (let == "BA")
            value += 5;

        if (value > last_value)
        {
            ns_dec = !ns_dec;
        }
        else
        {
            cout << "licytacja niepoprawna\n";
            return 0;
        }
        last_value = value;
    }
    if (ns_dec)
        cout << "NS\n";
    else
        cout << "WE\n";
}
