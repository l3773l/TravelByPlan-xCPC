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

struct cstar {
    int cnt;
    int head[MAXN], nxt[MAXM << 1], to[MAXM << 1];
    void adde(int x, int y) { nxt[++cnt] = head[x], head[x] = cnt, to[cnt] = y; }
}

#define Forg(i, g, u) for (int i = g.head[u]; i; i = g.nxt[i])

void dfs(int u, int fa) {
    fat[u] = fa;
    Forg (i, g, u) {
        int v = g.to[i];
        if (v == fa) continue;
        dfs(v, u);
    }
}

int n, m;
int x, y;
void solve() {
    cin >> n >> m;
    For (i, 1, n - 1) cin >> x >> y, g.adde(x, y), g.adde(y, x), ++deg[x], ++deg[y];
    dfs(n, 0);
    For (i, 1, m)  
}

int T;
int main() {
    cin >> T;
    while (T--) solve();
}