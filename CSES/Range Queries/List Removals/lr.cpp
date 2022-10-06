// time limit exceeded
#include <bits/stdc++.h>
using namespace std;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

struct item
{
    item* next = nullptr;
    int val;
    item(int val): val(val) {}
};

int n;
int main()
{
    scanf("%d", &n);

    int first;
    scanf("%d", &first);
    item* head = new item(first);

    item* last = head;
    for (int i = 1; i < n; ++i)
    {
        int in;
        scanf("%d", &in);
        last->next = new item(in);
        last = last->next;
    }
#if DEBUG
    item* i = head;
    while (i)
    {
        LOG("%d\n", i->val);
        i = i->next;
    }
#endif
    for (int i = 0; i < n; ++i)
    {
        int rem;
        scanf("%d", &rem);
        if (rem == 1)
        {
            printf("%d ", head->val);
            head = head->next;
        }
        else
        {
            item* it = head;
            item* last;
            for (int j = 1; j < rem; ++j)
            {
                last = it;
                it = it->next;
            }
            printf("%d ", it->val);
            last->next = it->next;
        }
    }
    printf("\n");
}

