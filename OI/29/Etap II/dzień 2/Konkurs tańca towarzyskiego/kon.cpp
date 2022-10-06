#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int q;

vector<pair<int, int>> e;

int main() {
    scanf("%d", &q);

    e.emplace_back(1, 2);
    e.emplace_back(2, 1);
    int n = 2;

    for (int i = 0; i < q; i++) {
        char type;
        int x;
        scanf(" %c%d", &type, &x);
        LOG("\t%c %d\n", type, x);
        if (type == 'W') {
            n++;
            e.emplace_back(n, x);
            e.emplace_back(x, n);
        } else if (type == 'Z') {
            n++;
            sort(e.begin(), e.end());
            //LOG("sorted\n");
            auto it = lower_bound(e.begin(), e.end(), make_pair(x, 0));
            stack<pair<int, int>> buff;
            while (it != e.end() && it->first == x) {
                buff.emplace(it->second, n);
                buff.emplace(n, it->second);
                it++;
            }
            //LOG("buffered\n");
            while (!buff.empty()) {
                e.push_back(buff.top());
                buff.pop();
            }
            //LOG("add\n");
        } else { // type == '?'
            sort(e.begin(), e.end());
            auto itb = lower_bound(e.begin(), e.end(), make_pair(x, 0));
            //LOG("got start\n");
            auto ite = upper_bound(e.begin(), e.end(), make_pair(x, (int)1e9));
            //LOG("got end\n");
            int count = distance(itb, ite);
            printf("%d\n", count);
        }
    }
}

