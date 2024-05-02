#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (auto i = (a), i##__end = (b); i <= i ##__end; ++i)
using ll = long long;
using lf = long double;
#define fi first
#define se second
using pii = pair<int, int>;
const int N = 100 + 7;
pii A[N];
lf eps = 1e-8;
lf inf = 1e8 + 7;
void sol() {
	lf ans = inf;
	int n;
	cin >> n;
	For (i, 1, n) cin >> A[i].fi >> A[i].se;
	For (i, 1, n) For (j, i + 1, n) For (k, j + 1, n) {
		lf a = A[i].fi, b = A[i].se, c = A[j].fi, d = A[j].se, e = A[k].fi, f = A[k].se;
		lf x1 = c - a, y1 = d - b, x2 = e - a, y2 = f - b;
		#define squ(a) ((a) * (a))
		lf area = fabs(x1 * y2 - x2 * y1) / 2.0;
		if (area > eps) ans = min(ans, area);
//		cout << i << " " << j << " " << k << endl;
//		cout << area << endl;
	}
	if (ans < eps || ans == inf) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) sol();
}


