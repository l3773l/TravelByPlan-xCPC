#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define For(i, a, b) for (auto i = (a), i##__end = (b); i <= i ##__end; ++i)
void sol() {
	ll x, y;
	cin >> x >> y;
	ll g = __gcd(x, y);
	cout << 1 << " " << x * y / g / g << endl;
}
const int mod = 998244353;
int main() {
	int a;
	cin >> a;
	For (i, 1, mod) {
		ll b = 1ll * a * i % mod;
		if (__gcd((ll)i, b) == 1) cout << b << "/" << i << endl;
	}
}
