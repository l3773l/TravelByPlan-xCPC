#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ll = long long;
using lf = long double;
using pii = pair<int, int>;
#define fi first
#define se second
#define pb push_back
#define For(i, a, b) for (auto i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i, a, b) for (auto i = (a), i##__end = (b); i >= i##__end; --i)

const int N = 1e5 + 7;

int n, x;
int d[N];
int a[N];
queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> x;
	cin >> a[0];
	
	fill(d, d + n, INT_MAX / 3);
	d[0] = 0;
	int mi = INT_MAX;
	if (a[0] == 0) {
		q.push(1); d[1] = 2;
		mi = 1;
	} else {
		q.push(a[0]); d[a[0]] = 1;
	}
	
	For (i, 1, n - 1) {
		cin >> a[i];
		a[i] = (i + a[i]) % n;
		if (a[i] != 0) mi = min(mi, a[i]);
	}
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
//		cout << u << endl;
		auto upd = [&](int v) {
			if (d[v] > d[u] + 1) d[v] = d[u] + 1, q.push(v);
		};
		if (u >= mi && u != n - 1) upd(u + 1);
		if (a[u] != 0 && a[u] != u) upd(a[u]);
	}
	
//	cout << "dists" << endl;
//	For (i, 0, n - 1) cout << d[i] << " "; cout << endl;
	cout << d[x] << endl;
	return 0;
}

