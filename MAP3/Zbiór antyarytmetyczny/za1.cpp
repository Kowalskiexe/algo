#include <bits/stdc++.h>

using namespace std;
int n,ost;

int main()
{
    cin>>n;
    
    if(n>1414){
        printf("NIE\n");
        return 0;
    }
    
    cout<<1<<" ";
m   ost = 1;
    
    for(int i = 1; i<n;i++){
        ost+=i;
        printf("%d ", ost);
        //cout<<ost<<" ";
    }
    
}

