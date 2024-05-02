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

void solve() {
	i64 a, b, m;
	cin >> a >> b >> m;

	i64 currentTime = 0;
	i64 aTimer = 0, bTimer = 0;
	i64 counter = 0;
	while (currentTime <= m) {
		if (aTimer == 0 && bTimer == 0) {
			counter += 2;
			aTimer = a;
			bTimer = b;
		} else if (aTimer == 0) {
			++counter;
			aTimer = a;
		} else if (bTimer == 0) {
			double valueA = a - aTimer;
			valueA /= a;
			double valueB = bTimer;
			valueB /= b;
			
			if (valueA > valueB) {
				currentTime += aTimer;
				aTimer = 0;
				continue;
			} else {
				counter++;
				bTimer = b;
			}
		} else {
			assert(("Unreachable", false));
		}
		
		auto toTime = min(aTimer, bTimer);
		currentTime += toTime;
		aTimer -= toTime;
		bTimer -= toTime;
	}
	
	cout << counter * 160 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}

