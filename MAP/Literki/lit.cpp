#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

char A[(int)1e6 + 1];
char B[(int)1e6 + 1];
int length;

int main()
{
    scanf("%s\n%s", A, B);
    length = strlen(A);
    LOG("%d\n", length);

    int res = 0;
    for (int i = 0; i < length; ++i)
    {
        if (A[i] != B[i])
        {
            res++;
            LOG("before:\n\t%s\n\t%s\n", A, B); 
            char from = B[i];
            char to = A[i];
            for (int j = i; j < length; ++j)
            {
                if (A[j] == from)
                    A[j] = to;
                if (B[j] == from)
                    B[j] = to;
            }
            LOG("after:\n\t%s\n\t%s\n", A, B); 
        }
    }
    printf("%d\n", res);
}
