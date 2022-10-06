#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

struct item
{
    int id, pit;
    bool type;
    item(int id, int pit, bool type): id(id), pit(pit), type(type) {}
    bool operator<(const item& other)
    {
        if (this->pit == other.pit)
            return this->type && !other.type;
        return this->pit < other.pit;
    }
};

vector<item> cus;
int n;
int main()
{
    scanf("%d", &n);
    cus.reserve(n * 2);
    for (int i = 0; i < n; ++i)
    {
        int arr, dep;
        scanf("%d %d", &arr, &dep);
        cus.emplace_back(i, arr, true);
        cus.emplace_back(i, dep, false);
    }

    sort(cus.begin(), cus.end());

    int count = 0;
    set<int> free;
    for (int i = 1; i <= n; ++i)
        free.insert(i);
    unordered_map<int, int> occ;
    vector<int> ord(n);
    for (int i = 0; i < 2 * n; ++i)
    {
        LOG("pit %d\n", cus[i].pit);
        if (cus[i].type)
        {
            int nr = *free.begin();
            free.erase(free.begin());
            occ[cus[i].id] = nr;
            LOG("new occ (%d) at %d\n", cus[i].id, nr);
            ord[cus[i].id] = nr;
        }
        else
        {
            int nr = occ[cus[i].id];
            occ.erase(cus[i].id);
            free.insert(nr);
            LOG("freeing %d from (%d)\n", nr, cus[i].id);
        }
        count = max(count, (int)occ.size());
    }

    printf("%d\n", count);
    for (auto i : ord)
        printf("%d ", i);
    printf("\n");
}
