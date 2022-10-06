#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void init(int n, int s);
void build(int x, int y, int t);
int path(int x, int y);

int main()
{
    int N, Q;
    cin >> N >> Q;
    init(N, 0);
    for(int q=0; q<Q; q++)
    {
        string command;
        int x, y, t;
        cin >> command >> x >> y;
        if (command=="B")
        {
            cin >> t;
            build(x,y,t);
        }
        else
            cout << path(x,y) << endl;
    }
}
