#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i,a,b) for (int i = (a), i##__end = (b); i >= i##__end; --i)
typedef long long ll;
typedef long double lf;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fl(s) s.begin(), s.end()

const int mod = 1e9 + 9;

struct Z {
    int v;
    Z() : v(0) {}
    Z(int _v) : v(_v) { assert(v < mod); } 


    auto operator+=(Z b) {
        v += b.v;
        if (v >= mod) v -= mod;
        return this;
    }
    friend Z operator+(Z a, Z b) {
    int c = a.v + b.v;
    if (c > mod) c -= mod;
    return c;
    }

    friend Z operator-(Z a, Z b) {
        int c = a.v - b.v;
        if (c < 0) c += mod;
        return c;
    }

    friend Z operator*(Z a, Z b) { return 1ll * a.v * b.v % mod; }

    Z qpow(Z x, int y) { Z r = 1 % mod; for (; y; x = x * x, y >>= 1) if (y & 1) r = r * x; return r; }
    Z inv() { return qpow(*this, mod - 2); }
    friend Z operator/(Z a, Z b) { return a * b.inv(); }
};


int m, k;
int main() {
    cin >> m >> k;
    Z leaf = 1, E = 0, ans = 0;
    For (i, 1, k) {
        Z t = E / leaf + 1;
        E += (m - 1) * t + 1;
        ans += m * t;
        leaf += m - 1;
    }
    cout << ans.v << endl;
}