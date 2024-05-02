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
	cin >> n;
	ll L, p;
	For (i, 1, n) cin >> p, L = i == 1 ? p : lcm(p, L);
//	cout << L << endl;
	p = L * 8 + 1;
//	cout << p << endl;
	while (1) {
		ll sq = floor(sqrt(p));
		cout << p << " " << sq << " " << sq * sq << endl;
		if (sq * sq == p) {
//			cout << sq << endl;
			ll ans = (sq - 1);
			if (ans % 2 == 0) {
				ans /= 2;
				cout << ans << endl;
				return 0;
			}
		}
		p += L * 8;
	}
}
