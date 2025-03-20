#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (auto i = (a), i##__end = (b); i <= i ##__end; ++i)
using ll = long long;
using lf = long double;
#define fi first
#define se second
using pii = pair<int, int>;
const int N = 1e7 + 7;
const int mod = 998244353;

vector<int> pri;
int minp[N];

void pre(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!minp[i]) {
      pri.push_back(i);
      minp[i] = i;
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      minp[i * pri_j] = pri_j;
      if (i % pri_j == 0) {
        break;
      }
    }
  }
}


void sol() {
	ll a, b;
	cin >> a >> b;
	ll g = __gcd(a, b);
	ll l1 = a * b / g;
	ll ans;
	if (a == b) {
		cout << 0 << endl;
		return;
	}
	if (g != 1) ans = min(l1, a + b);
	else {
		ll ma = minp[a], mb = minp[b];
		ll l21 = 2 * (a + b);
		ll l22 = ma * b + a;
		ll l23 = mb * a + b;
		ll l31 = a + b + min(ma * mb, 2 * (ma + mb));
		ll l32 = 2 * a + b + 2 * mb;
		ll l33 = 2 * b + a + 2 * ma;
		ans = min({l1, l21, l22, l23, l31, l32, l33});
	}
	cout << ans << endl;
}

int a;
int main() {
	int T;
	cin >> T;
	pre(N - 5);
//	For (i, 1, 100) cout << minp[i] << " ";
	while (T--) sol();
}


