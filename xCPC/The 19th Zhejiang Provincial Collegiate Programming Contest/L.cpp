#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (ll i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i, a, b) for (auto i = (a), i##__end = (b); i >= i##__end; --i)
using ll = long long;
const int N = 1e6 + 7;
int a[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	For (i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll s = 0;
	ll j = 1;
	ll ans = 0;
	For (i, 1, n) {
		s += a[i];
		while (j <= i && 1ll * a[j] * i <= s) j++;
		ans = max(ans, (ll)max(i - j + 1, 0ll));
//		cout << i << " " << s << " " << j << " " << ans << endl;
	}
	
	cout << ans << endl;
}
