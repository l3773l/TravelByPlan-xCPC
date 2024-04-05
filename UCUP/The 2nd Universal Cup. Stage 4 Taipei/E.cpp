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


int p, k, t;

ll qpow(ll x, int y) { ll r = 1 % p; for (; y; x = 1ll * x * x % p, y >>= 1) if (y & 1) r = 1ll * r * x % p; return r; }

int main() {
    cin >> p >> k >> t;
    cout << qpow(p - k, t) << endl;
}