#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
using ll = long long;

int mod = 998244353;

int mul(int x, int y) { 
	return 1ll * x * y % mod;
}

int add(int x, int y) {
	ll r = x + y;
	if (r >= mod) r -= mod;
	return r;
}

int qpow(int x, int y) {
	int r = 1 % mod;
	for (; y; x = mul(x, x), y >>= 1) if (y & 1) r = mul(r, x);
	return r;
}

int inv(int x) {
	return qpow(x, mod - 2);
}

int n, m;
int main() {
	cin >> n >> m;
	if (n == 1){
		For (i, 1, m) cout << 1 << " ";
		cout << endl;
		return 0;
	}
	For (i, 1, m) {
		int ans = qpow(mul((m - i), inv(m - 1)), n);
		cout << ans << " ";
	}
	cout << endl;
}
