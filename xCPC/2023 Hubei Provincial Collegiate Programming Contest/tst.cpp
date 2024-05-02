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
	for (; y; x = mul(x, x), y >>= 1) if (y & 1) r = add(r, x);
	return r;
}

ll gcd(ll a, ll b) {
	while (b != 0) {
		ll t = a;
		a = b;
		b = t % a;
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int n;
int main() {
	
	cin >> n;
	For (i, 1, 500) {
		int t = mul(i, n);
		if (t <= i && gcd(t, i) == 1)
		cout << i << " " << mul(i, n) << endl;
	}
}
