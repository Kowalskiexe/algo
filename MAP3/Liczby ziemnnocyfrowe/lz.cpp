#include <bits/stdc++.h>

using namespace std;

int suma, sumaabsurdalna, ostatnia = 9, n;

int cyfry[10000001];

void wypiszCyfry()
{
    if(n<4 && n>1)
    {
        swap(cyfry[n-1],cyfry[n-2]);
    }
    for(int i = 0;i<n;++i)
    {
        if(cyfry[i]>0)
        {
            printf("%d", cyfry[i]);
        }
    }
}

int main()
{
    cin >> suma;
    int i = 0;
    while(sumaabsurdalna<suma)
    {
        //cout << "wykoanien" << endl;
        if(ostatnia==9)
        {
            ostatnia = 8;
            sumaabsurdalna+=8;
            cyfry[i] = 8;
            n++;
        }
        else
        {
            ostatnia = 9;
            sumaabsurdalna+=9;
            cyfry[i] = 9;
            n++;
        }
        i++;
                //cout << sumaabsurdalna << endl;
    }
    if(suma==sumaabsurdalna)
    {
    }
    else
    {
        int k = sumaabsurdalna-suma;
        cyfry[0] -= k;
    }
    wypiszCyfry();
}
