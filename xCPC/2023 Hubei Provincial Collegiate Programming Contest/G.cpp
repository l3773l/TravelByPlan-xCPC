#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
using ll = long long;
#define fi first
#define se second

int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

const int N = 3e3 + 7;

int n, m, k;
int x, y;
int a[N][N];
ll cost[N][N];
int rx, ry;
using pii = pair<int, int>;
priority_queue<pair<int, pii>> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	For (i, 1, k) {
		cin >> x >> y, a[x][y] = -i;
		if (i == 1) rx = x, ry = y;
	}
	For (i, 1, n) For (j, 1, m) {
		char c;
		cin >> c;
		if (!a[i][j]) a[i][j] = c;
	}
	

	cost[rx][ry] = -1;
	q.push({0, {rx, ry}});
	while (!q.empty()) {
		auto u = q.top(); q.pop();
		int x = u.se.fi, y = u.se.se;
		int cop = -u.fi;
//		cout << x << " " << y << " " << cop << endl;
		if (cop > cost[x][y] && cost[x][y] != -1) continue;
		For (i, 0, 3) {
			int nx = x + dx[i], ny = y + dy[i];
			#define na a[nx][ny]
			if (na == 0 || na == '#') continue;
//			cout << x << " " << y << " " << nx << " " << ny << endl;
			ll t;
			if (na < 0) {
				ll st = -na;
//				cout << "st: " << st << endl;
				ll cl = max(0ll, k - (cop + st) + 1);
				if (cl <= 1) t = 1;
				else t = cl;
			} else t = 1;
//			cout << t << endl;
			if (!cost[nx][ny] || cost[nx][ny] > cop + t) {
				cost[nx][ny] = cop + t;
				q.push({-(cop + t), {nx, ny}});
			}
		}
	}

	cost[rx][ry] = 0;
//	For (i, 1, n) For (j, 1, m) cout << a[i][j] << " \n"[j == m];
//	cout << endl;
//	For (i, 1, n) For (j, 1, m) cout << cost[i][j] << " \n"[j == m];
//	
	unsigned long long r = 0;
	For (i, 1, n) For (j, 1, m) r += cost[i][j] * cost[i][j];
	
	cout << r << endl;
}
	
