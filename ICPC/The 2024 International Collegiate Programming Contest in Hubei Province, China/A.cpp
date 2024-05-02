#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sol() {
	ll x, y;
	cin >> x >> y;
	ll g = __gcd(x, y);
	cout << 1 << " " << x * y / g / g << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) sol();
}
