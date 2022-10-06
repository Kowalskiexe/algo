#include <bits/stdc++.h>
//using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int n, k;
int size = 0;
class Element
{
public:
    int value;
    Element* next;
    Element(int value): value(value) {}
};

int main()
{
    scanf("%d %d", &n, &k);

    Element* first = new Element(1);
    Element* last = first;
    for (int i = 2; i <= n; ++i)
    {
        Element* el = new Element(i);
        last->next = el;
        last = el;
    }
    last->next = first;
    size = n;
#if DEBUG
    Element* dcur = first;
    for (int i = 0; i < n * 2; ++i)
    {
        LOG("%d ", dcur->value);
        dcur = dcur->next;
    }
    LOG("\n");
#endif

    Element* cur = last;
    while (size > 0)
    {
        int passed = 0; 
        while (passed <= (k % size))
        {
            last = cur;
            cur = cur->next;
            passed++;
        }
        printf("%d ", cur->value);
        last->next = cur->next;
        size--;
    }

    printf("\n");
}

