#include <bits/stdc++.h>
using namespace std;

bool check(__int128_t p, __int128_t m, __int128_t k) {
    return ((1 + k * p) ^ (p-1)) <= m;
}

void solve() {
    __int128_t p, m;
    {
        size_t po, mo;
        cin >> po >> mo;
        p = po;
        m = mo;
    }

    
    size_t ans = 0;
    __int128_t ll = 0;
    __int128_t rr = 1000'000'000'000'000'000ull;
    while (rr > ll) {
        auto mid = (rr+ll) / 2;
        if (check(p, m, mid*2)) {
            ll = mid + 1;
        } else {
            rr = mid;
        }
    }

    ans += ll;

    ll = 0;
    rr = 1000'000'000'000'000'000ull;
    while (rr > ll) {
        auto mid = (rr+ll) / 2;
        if (check(p, m, mid*2+1)) {
            ll = mid + 1;
        } else {
            rr = mid;
        }
    }

    ans += ll;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}