#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (auto i = (a), i##__end = (b); i <= i ##__end; ++i)
using ll = long long;
using lf = long double;
#define fi first
#define se second
using pii = pair<int, int>;
const int N = 100 + 7;
const int mod = 998244353;

int mul(int x, int y) {
	return 1ll * x * y % mod;
}

int add(int x, int y) {
	int r = x + y;
	if (r >= mod) r -= mod;
	return r;
}

int qpow(int x, int y) {
	int r = 1 % mod;
	for (; y; x = mul(x, x), y >>= 1) if (y & 1) r = mul(r, x);
	return r;
}

int inv(int x) { return qpow(x, mod - 2); }

int a;
int main() {
	int n;
	cin >> n;
	int s = 0;
	For (i, 1, n) cin >> a, s = add(s, a);
	int t = 1;
	For (i, 1, n) t = mul(t, i);
	int ans = mul(s, inv(n));
	cout << ans << endl;
}


