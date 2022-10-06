#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int q;

vector<vector<int>> adj;

int main() {
    scanf("%d", &q);

    adj.resize((int)1e6 + 17);

    adj[1].push_back(2);
    adj[2].push_back(1);
    int count = 2;

    for (int i = 0; i < q; i++) {
        char type;
        int x;
        scanf(" %c%d", &type, &x);
        LOG("\t%c %d\n", type, x);
        if (type == 'W') {
            count++;
            adj[count].push_back(x);
            adj[x].push_back(count);
        } else if (type == 'Z') {
            count++;
            adj[count] = adj[x];
            // SLOW PART!!!
            for (int u : adj[count]) 
                adj[u].push_back(count);
        } else { // type == '?'
            printf("%ld\n", adj[x].size());
        }
    }
}

