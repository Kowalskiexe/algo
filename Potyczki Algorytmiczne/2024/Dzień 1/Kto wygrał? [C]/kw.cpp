#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#define DOUT cout
#else
#define LOG(...)
#define DOUT if(0) cout
#endif

int main() {
    vector<int> a(18), b(18);
    for (int i = 0; i < 18; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < 18; i++)
        scanf("%d", &b[i]);
    int a_score = 0, b_score = 0;
    for (int s : a)
        a_score += s;
    for (int s : b)
        b_score += s;
    if (a_score == b_score) {
        for (int t = 10; t >= 0; t--) {
            int a_count = 0, b_count = 0;
            for (int i = 0; i < 18; i++) {
                if (a[i] == t)
                    a_count++;
            }
            for (int i = 0; i < 18; i++) {
                if (b[i] == t)
                    b_count++;
            }
            if (a_count > b_count) {
                printf("Algosia\n");
                return 0;
            } 
            if (b_count > a_count){
                printf("Bajtek\n");
                return 0;
            }

        }
        printf("remis\n");
        return 0;
    }
    if (a_score > b_score)
        printf("Algosia\n");
    else
        printf("Bajtek\n");
}
