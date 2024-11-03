#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

using ll = long long;

#define fi first 
#define se second

const int mod = 998244353;

struct Z {
    int v;
    Z() : v(0) {}
    Z(int x) : v((x %= mod, (x < 0 ? x + mod : x))) {}
    Z(ll x) : v((x %= mod, (x < 0 ? x + mod : x))) {}
    Z operator*=(Z y) {
        v = 1ll * v * y.v % mod; return *this;
    }
    Z operator+=(Z y) {
        if ((v += y.v) >= mod) v -= mod; return *this;
    }
    Z operator-=(Z y) {
        if ((v -= y.v) < 0) v += mod; return *this;
    }
    Z operator+(Z y) { Z r = *this; return r += y; }
    Z operator-(Z y) { Z r = *this; return r -= y; }
    Z operator*(Z y) { Z r = *this; return r *= y; }
    Z qpow(Z x, ll y) {
        Z r = 1 % mod;
        for (; y; x *= x, y >>= 1) if (y & 1) r *= x;
        return r;
    }
    Z inv() { return qpow(v, mod - 2); }
    Z operator==(Z y) { return v == y.v; }
    Z operator/=(Z y) { *this *= y.inv(); return *this; }
    Z operator/(Z y) { Z r = *this; return r /= y; }

};    
ostream &operator<<(ostream &os, Z x) {
    os << x.v;
    return os;
}

Z sq(Z x) { return x * x; }

Z one(1);

const int N = 1e5 + 7;

int n;

vector<int> e[N];

Z ans;

pair<Z, Z> dfs(int u, int fa) {
    Z szu = 1;
    Z sos_szu = 0;
    Z s_sos_szv = 0, sos_sos_szv = 0;
    for (auto v : e[u]) {
        if (v != fa) {
            auto [szv, sos_szv] = dfs(v, u);
            szu += szv;
            sos_szu += sos_szv;
            Z cb1 = sq(szv) * sq(szv - n);
            Z cb2 = Z(2) * (sos_szv - sq(szv)) * sq(szv - n);
            s_sos_szv += sos_szv;
            sos_sos_szv += sq(sos_szv);
            ans += cb1 + cb2;
        }
    }
    sos_szu += sq(szu);
    ans += sq(s_sos_szv) - sos_sos_szv;
    return {szu, sos_szu};
}

#define pb push_back

void sol() {
    cin >> n;

    For (i, 1, n) e[i].clear();

    For (i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v), e[v].pb(u);
    }
    
    ans = 0;
    dfs(1, 0);

    Z denom = sq(one * n * (n - 1) / 2);

    cout << (ans / denom).v << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}