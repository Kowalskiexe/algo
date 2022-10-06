#include <bits/stdc++.h>

typedef long long ll;
int n;

void inline quary(char* num)
{
    printf("%s ", num);
    int l = strlen(num);
    if (l == 1 && (num[0] == '1' || num[0] == '4'))
    {
        printf("\n");
        return;
    }
    ll sum = 0;
    for (int i = 0; num[i] != '\0'; ++i)
    {
        ll digit = num[i] - '0';
        sum += digit * digit;
    }

    char tmp[68];
    int length = 0;
    while (sum > 0)
    {
        tmp[length] = sum % 10 + '0';
        sum /= 10;
        length++;
    }

    char new_num[68];
    for (int i = 0; i < length; ++i)
        new_num[i] = tmp[length - i - 1];
    new_num[length] = '\0';

    quary(new_num);
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        char num[68];
        scanf("%s", num);
        quary(num);
    }
}
