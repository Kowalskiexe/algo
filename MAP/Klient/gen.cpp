#include <bits/stdc++.h>

bool inline is_prime(int n)
{
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    for (int i = 2; i < 1'000'000'000; ++i)
    {
       if (is_prime(i))
          printf("%d,", i);
    }
} 
