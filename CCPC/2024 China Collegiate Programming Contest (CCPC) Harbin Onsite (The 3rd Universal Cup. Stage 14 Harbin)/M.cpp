#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        int lst = 1, lst1 = n;
        ll ans = 0;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                if (lst) {
                   ans += (i - lst) * n / lst;
                   lst = i;
                } else lst = i;
                if (lst1) {
                    ans += (lst1 - n / i) * i;
                    lst1 = n / i;
                } else lst1 = n / i;
            }
        }
        if (lst != lst1) {
            ans += (lst1 - lst) * n / lst;
        }

        cout << ans + 1 << endl;
    }
}