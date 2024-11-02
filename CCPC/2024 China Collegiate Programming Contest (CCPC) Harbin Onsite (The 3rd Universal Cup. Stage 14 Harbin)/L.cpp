#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

using ll = long long;

#define fi first 
#define se second

const int mod = 998244353;

int mul(int x, int y) {
    return 1ll * x * y % mod;
}

int add(int x, int y) {
    int r = x + y;
    if (r >= mod) r -= mod;
    return r;
}

int sub(int x, int y) {
    int r = x - y;
    if (r < 0) r += mod;
    return r;
}

int qpow(int x, ll y) {
    int r = 1;
    for (; y; x = mul(x, x), y >>= 1) if (y & 1) r = mul(r, x);
    return r;
}

int inv(int x) {
    return qpow(x, mod - 2);
}

const int N = 1e5 + 7;

int n;

int sz[N];

vector<int> e[N];

void dfs1(int u, int fa) {
    sz[u] = 1;
    for (auto v : e[u]) {
        if (v != fa) {
            dfs1(v, u);
            sz[u] += sz[v];
        }
    }
}

int ans1, ans2;

int mem[N], pmem[N];

int calc(int sumsv2, int su) {
    return sub(mul(su, su), sumsv2);
}

void dfs2(int u, int fa) {
    int ssv2 = 0;
    for (auto v : e[u]) {
        if (v != fa) {
            ssv2 = add(ssv2, mul(sz[v], sz[v]));
        }
    }

    mem[u] = calc(ssv2, sz[u]);

    int fsz2 = mul(sub(n, sz[u]), sub(n, sz[u]));
    int base = add(ssv2, fsz2);
    for (auto v : e[u]) {
        if (v != fa) {
            int szv2 = mul(sz[v], sz[v]);
            int fssv2 = sub(base, szv2);
            pmem[v] = calc(fssv2, sz[u]);
            dfs2(v, u);
        }
    }

    ans1 = add(ans1, mul(mem[u], pmem[u]));

    int smemv = 0, smemv2 = 0;
    for (auto v : e[u]) {
        if (v != fa) {
            smemv = add(smemv, mem[v]);
            smemv2 = add(smemv2, mul(mem[v], mem[v]));
        }
    }

    int contrib = add(mul(pmem[u], smemv), mul(sub(mul(smemv, smemv), smemv2), inv(2)));
    ans2 = add(ans2, contrib);
}

#define pb push_back

void sol() {
    cin >> n;
    For (i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v), e[v].pb(u);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    cout << add(ans1, ans2) << endl;    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}