#include <iostream>
#include <string>
using namespace std;
int main()
{

    string napis1, napis2;
    cin>>napis1>>napis2;
    int t[napis1.size()+5][napis2.size()+5];

    for(int i=0; i<=napis1.size(); ++i)
        t[i][0]=0;
    for(int j=0; j<=napis2.size(); ++j)
        t[0][j]=0;
    for(int i=1; i<=napis1.size(); ++i)
        for(int j=1; j<=napis2.size(); ++j)
            if(napis1[i-1]==napis2[j-1])
                t[i][j]=t[i-1][j-1] + 1;
            else
                t[i][j]=max(t[i-1][j], t[i][j-1]);
    char tww[t[napis1.size() + 5][napis2.size()]+5];
    int a=napis1.size(), b=napis2.size();
    int z=0;
    while(1)
    {
        if(t[a][b]==t[a-1][b])
              --a;
        else if(t[a][b-1]==t[a][b])
              --b;
        else
        {
            tww[z]=napis2[b-1];
            --a;
            --b;
            ++z;
        }
        if(a<=0 || b<=0)
            break;
        if(z>t[napis1.size()][napis2.size()]-1)
            break;
    }
    for(int i=z-1; i>=0; --i)
        cout<<tww[i];

    return 0;
}
