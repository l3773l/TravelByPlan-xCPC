#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
using ll = long long;

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
	ll p;
	cin >> p;
	For (i, 2, p) {
		if (1ll * i * i % p == 1) cout << p << " " << i << endl;
	}
//	for (ll i = 1; i <= 1e9; ++i) {
//		
//	}
}
