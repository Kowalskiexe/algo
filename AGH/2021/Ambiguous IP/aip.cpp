#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char ip[51];
int n;
int printed = 0;

vector<string> output;

bool inline is_valid(int s, int e)
{
    if (ip[s] == '0' && s != e)
    {
        LOG("\t%d %d has a leading 0\n", s, e);
        return false;
    }
    int val = 0;
    int pow = 1;
    int i = e;
    while (s - 1 != i)
    {
        val += (ip[i] - '0') * pow;
        i--;
        pow *= 10;
    }
    LOG("\t %d %d: %d\n", s, e, val);
    return val <= 255;
}

// put a dot after d0, d1, d2.
void inline print(int d0, int d1, int d2)
{
    string s;
    for (int i = 0; i < n; ++i)
    {
        LOG("%c", ip[i]);
        s.push_back(ip[i]);
        if (i == d0 || i == d1 || i == d2)
        {
            LOG(".");
            s.push_back('.');
        }
    }
    output.push_back(s);
    LOG("\n");
    printed++;
}

void inline same(int l)
{
    vector<int> dots;
    bool valid = true;
    int idx = 0;
    for (int part = 0; part < 4; ++part)
    {
        if (is_valid(idx, idx + l - 1))
        {
            idx += l;
            dots.push_back(idx - 1);
        }
        else
        {
            valid = false;
            break;
        }
    }
    if (valid)
    {
        LOG("dots:\n");
        for (int d : dots)
            LOG("%d ", d);
        LOG("\n");
        sort(dots.begin(), dots.end());
        dots.pop_back();
        print(dots[0], dots[1], dots[2]);
    }
}

// ul - unique one's length
// ol - other ones' length
void inline one_unique(int ul, int ol)
{
    for (int i = 0; i < 4; ++i) // ul
    {
        int idx = 0;
        bool valid = true;
        vector<int> dots;
        for (int part = 0; part < 4; ++part)
        {
            int l;
            if (part == i)
                l = ul;
            else
                l = ol;
            if (is_valid(idx, idx + l - 1))
            {
                idx += l;
                dots.push_back(idx - 1);
            }
            else
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            sort(dots.begin(), dots.end());
            dots.pop_back();
            print(dots[0], dots[1], dots[2]);
        }
    }
}

void inline two_two(int l1, int l2)
{
    for (int i = 0; i < 3; ++i) // first pos
    {
        for (int j = i + 1; j < 4; ++j) // second pos
        {
            vector<int> dots;
            bool valid = true;
            int idx = 0;
            for (int part = 0; part < 4; ++part)
            {
                int l;
                if (part == i || part == j)
                    l = l1;
                else
                    l = l2;
                if (is_valid(idx, idx + l - 1))
                {
                    idx += l;
                    dots.push_back(idx - 1);
                }
                else
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                sort(dots.begin(), dots.end());
                dots.pop_back();
                LOG("dots:\n");
                for (int k : dots)
                    LOG("%d ", k);
                LOG("\n");
                print(dots[0], dots[1], dots[2]);
            }
        }
    }
}

void inline two_unique(int u1, int u2, int o)
{
    for (int i = 0; i < 4; ++i) // u1
    {
        for (int j = 0; j < 4; ++j) // u2
        {
            if (j == i) continue;
            int idx = 0;
            bool valid = true;
            vector<int> dots;
            for (int part = 0; part < 4; ++part)
            {
                int l;
                if (part == i)
                    l = u1;
                else if (part == j)
                    l = u2;
                else
                    l = o;
                if (is_valid(idx, idx + l - 1))
                {
                    idx += l;
                    dots.push_back(idx - 1);
                }
                else
                {
                    LOG("\tabort\n");
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                sort(dots.begin(), dots.end());
                dots.pop_back();
                print(dots[0], dots[1], dots[2]);
            }
        }
    }
}

int main()
{
    scanf("%s", ip);
    n = strlen(ip);
    LOG("n: %d\n", n);

    switch (n)
    {
        case 12:
            LOG("1) s:\n");
            same(3); // 4 * 3 = 12
            break;
        case 11:
            LOG("1) ou:\n");
            one_unique(2, 3); // 2 + 3 * 3 = 11
            break;
        case 10:
            LOG("1) ou:\n");
            one_unique(1, 3); // 1 + 3 * 3 = 10
            LOG("2) tt:\n");
            two_two(2, 3); // 2 * 2 + 2 * 3 = 10
            break;
        case 9:
            LOG("1) tu:\n");
            two_unique(1, 2, 3); // 1 + 2 + 2 * 3 = 9
            LOG("2) ou:\n");
            one_unique(3, 2); // 3 + 3 * 2 = 9
            break;
        case 8:
            LOG("1) s:\n");
            same(2); // 4 * 2 = 8
            LOG("2) tt:\n");
            two_two(1, 3); // 2 * 1 + 2 * 3 = 8
            LOG("3) tu:\n");
            two_unique(1, 3, 2); //1 + 3 + 2 * 2 = 8
            break;
        case 7:
            LOG("1) tu:\n");
            two_unique(2, 3, 1); // 2 + 3 + 2 * 2 = 7
            LOG("2) ou:\n");
            one_unique(1, 2); // 1 + 3 * 2 = 7
            break;
        case 6:
            LOG("1) ou:\n");
            one_unique(3, 1); // 3 + 3 * 1 = 6
            LOG("2) tt:\n");
            two_two(1, 2); // 2 * 1 + 2 * 2 = 6
            break;
        case 5:
            LOG("1) ou:\n");
            one_unique(2, 1); // 2 + 3 * 1 = 5
            break;
        case 4:
            LOG("1) s:\n"); // 4 * 1 = 4
            same(1);
            break;
    }
    sort(output.begin(), output.end());
    LOG("SORTED\n");
    for (string i : output)
        printf("%s\n", i.c_str());
    LOG("\n");
    LOG("printed: %d\n", printed);
    if (printed == 0)
        printf("NO\n");
}
