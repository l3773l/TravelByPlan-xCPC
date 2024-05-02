#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (ll i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i, a, b) for (auto i = (a), i##__end = (b); i >= i##__end; --i)
using ll = long long;
using lf = long double;
const lf INF = 1e8 + 7;
const int N = 1e3 + 7;

lf dis[N];
lf g[N + 2][N + 2];
bool vis[N];

void dij(int n, int s) {
  For (i, 1, n) dis[i] = INF;
  dis[s] = 0;
  for (int i = 1; i <= n; i++) {
    int u = 0;
	lf mind = INF;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && dis[j] < mind) u = j, mind = dis[j];
    vis[u] = true;
    For (i, 1, n) {
    	lf w = g[u][i];
    	if (dis[i] > dis[u] + w) dis[i] = dis[u] + w;
	}
  }
}

lf v1, v2;
int n;
using pii = pair<int, int>;
#define fi first
#define se second

lf cdis(pii a, pii b) {
	#define squ(a) ((a) * (a))
	return sqrt(squ(a.fi - b.fi) + squ(a.se - b.se));
}

lf cal(pii a, pii b) {
	lf d = cdis(a, b);
	if (3 * v2 >= d) return d / v2;
	else return 3.0 + (d - 3 * v2) / v1;
}

pii a[N];
pii s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	For (i, 1, n) cin >> a[i].fi >> a[i].se;
	cin >> s.fi >> s.se >> t.fi >> t.se;
	cin >> v1 >> v2;
	For (i, 1, n + 2) For (j, 1, n + 2) g[i][j] = INF;
	For (i, 1, n) {
		g[1][i + 1] = cdis(s, a[i]) / v1;
	}
	For (i, 1, n) {
		g[i + 1][n + 2] = cal(a[i], t);
	}
	g[1][n + 2] = cdis(s, t) / v1;
	For (i, 1, n) For (j, i + 1, n) g[i + 1][j + 1] = g[j + 1][i + 1] = cal(a[i], a[j]);
	For (i, 1, n + 2) g[i][i] = 0;
	
//	For (i, 1, n + 2) For (j, 1, n + 2) cout << setw(15) << g[i][j] << " \n"[j == n + 2];
	
	dij(n + 2, 1);
	
	cout << fixed << setprecision(12) << dis[n + 2] << endl;
}
