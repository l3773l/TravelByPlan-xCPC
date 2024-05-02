#include <bits/stdc++.h>
using namespace std;
void solve() {
	long long n, x, a, b;
	cin >> n >> x >> a >> b;
	cout << (n-x) * a + x * b << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
