#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (auto i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i, a, b) for (auto i = (a), i##__end = (b); i >= i##__end; --i)
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define pb push_back
const int N = 1000 + 7;


char a[N][N];
bool pa[N * N / 20];
vector<pii> v;

bool chk(pii a, pii b) {
	return (a.fi == b.fi && abs(a.se - b.se) == 7) || (a.se == b.se && abs(a.fi - b.fi) == 7);
}

char tmp[6][7] = {
"######",
"##..##",
"#....#",
"#....#",
"##..##",
"######",
};

	int n, m;
bool chkrd(int x, int y) {
	int sz = 6;
	if (x + sz > n || y + sz > m) return 0;
	For (i, 0, sz - 1) For (j, 0, sz - 1) {
		if (a[x + i][y + j] != tmp[i][j]) return 0;
	} 
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	int tpc = 0, tps = 0;
	For (i, 1, n) For (j, 1, m) cin >> a[i][j];
	For (i, 1, n - 1) For (j, 1, m - 1) if (chkrd(i, j)) v.pb({i, j});
//	for (auto t : v) cout << t.fi << " " << t.se << endl;
	int sz = v.size();
	For (i, 0, sz - 1) {
		if (pa[i]) continue;
		For (j, i + 1, sz - 1) {
			if (pa[j]) continue;
//			cout << i << " " << j << endl;
//			cout << chk(v[i], v[j]) << endl;
			if (chk(v[i], v[j])) {
				tpc++;
				pa[j] = 1;
				goto ok;
			}
		}
//		cout << i << endl;
		tps++;
		ok:;
	}
	cout << tpc << " " << tps << endl;
}
