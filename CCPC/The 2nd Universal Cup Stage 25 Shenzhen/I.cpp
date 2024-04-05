#include <bits/stdc++.h>
#include <ostream>
using namespace std;
#define For(i,a,b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i,a,b) for (int i = (a), i##__end = (b); i >= i##__end; --i)
typedef long long ll;
typedef __int128 lll;
typedef long double lf;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fl(s) s.begin(), s.end()

void wt(lll x) { if (x == 0) return; if (x < 0) cout << '-', x = -x; wt(x / 10); cout << int(x % 10); }

lll qpow(lll x, int y) { lll r = 1; for (; y; x *= x, y >>= 1) if (y & 1) r *= x; return r; }

int T;
ll n;
int k;
int main() {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        ll d = floor(pow(n, 1.0 / k));
        int ans = 0;
        ll mx = 1;
        if (k != 3) {
            while (qpow(mx + d, k)  <= n) mx++;
            mx += 2;
        }
        cout << "mx:" << mx << endl;
        For (i, 1, d) {
            if (n % i) continue;
            if (k == 3) {
                ll t = n / i;
                ll del = 12 * t - 3 * i * i;
                if (del <= 0) continue;
                ll sq = floor(sqrt(del));
                if (sq * sq != del) continue;
                ll up = -3 * i + sq;
                if (up <= 0 || up % 6 != 0) continue;
                ans++;
                continue;
            }
            ll l = 1, r = mx;
            while (l <= r) {
                ll a = (l + r) >> 1;
                lll v = qpow(a + i, k) - qpow(a, k);
                cout << a + i << " " << a << " "; wt(v); cout << endl;
                if (v > n) r = a - 1; 
                else if (v < n) l = a + 1; 
                else { ans++; break; }
            }
        }
        cout << ans << endl;
    }
}
