#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ll = long long;
using lf = long double;
using pii = pair<int, int>;
#define fi first
#define se second
#define pb push_back
#define For(i, a, b) for (auto i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i, a, b) for (auto i = (a), i##__end = (b); i >= i##__end; --i)

const int N = 500 + 3;

int n;
ll f[N];
string str[N];

void upd(int x) {
	static int n = 2;
	if (n < x) {
		For (i, n + 1, x) f[i] = f[i - 2] + f[i - 1];
//		For (i, n + 1, x) str[i] = str[i - 2] + str[i - 1];
		n = x;
	} 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	f[1] = 6;
	f[2] = 7;
	str[1] = "COFFEE", str[2] = "CHICKEN";
	str[3] = str[1] + str[2], str[4] = str[2] + str[3];
	str[5] = str[3] + str[4];
	 
	int T;
	cin >> T;
	upd(70);
	while (T--) {
		ll n, k;
		cin >> n >> k;
//		upd(n);
//		cout << "ok:";
//		cout << st[n].substr(k - 1, 10) << endl;
//		upd(n);
//		For (i, 1ll, n) cout << i << " " << f[i] << endl;
		if (n & 1) n = min(n, 71ll);
		else n = min(n, 72ll);
		while (n > 5) {
			if (k > f[n - 2]) k -= f[n - 2];
			n -= 2;
		}
		cout << n << " " << k << endl;
		cout << str[n].substr(k - 1, 10) << endl; 
	}
	return 0;
}

