#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        string eligible;
        int x;
        cin >> eligible >> x;
        if (eligible == "TAK") {
            if (count < 10) {
                cout << i << " ";
                count++;
            } else if (x < 2) {
                cout << i << " ";
                count++;
            }
        }
        if (count == 20)
            break;
    }
    cout << "\n";

    return 0;
}
