#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int x, y, s;
    Tree(int x, int y, int s): x(x), y(y), s(s) {}
    bool operator<(const Tree& other)
    {
        return this->s < other.s;
    }
};

int n, x, y;
vector<Tree> trees;

int inline solve(int i)
{
    int y1 = trees[i].y;
    int x1 = trees[i].x;
    int y2 = trees[i - 1].y;
    int x2 = trees[i - 1].x;
    int y3 = trees[i - 2].y;
    int x3 = trees[i - 2].x;

    int xa = x3 - x1;
    int ya = y3 - y1;
    int xb = x2 - x1;
    int yb = y2 - y1;

    int dot = xa * yb - xb * ya;

    xb = x - x1;
    yb = y - y1;

    int dot2 = xa * yb - xb * ya;

    if (dot * dot2 < 0)
        return -1;

    dot = abs(dot);
    dot2 = abs(dot2);
    
    if (dot2 < dot)
    {
        // dobrze
        return trees[i].s + trees[i - 1].s + trees[i - 2].s;
    }
    else
        return -1;
}

int main()
{
    scanf("%d %d %d", &n, &x, &y);

    trees.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int inx, iny, ins;
        scanf("%d %d %d", &inx, &iny, &ins);
        trees.emplace_back(inx, iny, ins);
    }

    sort(trees.begin(), trees.end());
    
#if DEBUG
    for (auto i : trees)
        printf("%d %d %d\n", i.x, i.y, i.s);
#endif

    for (int i = n - 1; i >= 2; --i)
    {
        int out = solve(i);
        if (out != -1)
        {
            printf("%d\n", out);
            return 0;
        }
    }
    printf("niemozliwe\n");
}
