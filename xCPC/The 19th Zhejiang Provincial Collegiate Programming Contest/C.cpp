#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, x, a;
	int ans = 0;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; ++i) cin >> a, ans += a >= x;
	for (int i = 1; i <= m; ++i) cin >> a, ans += a <= x;
	cout << ans << endl;
}
