#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0 << endl;
		return ;
	}
	
	bool sameEven = (a % 2) == (b % 2);
	if (a < b) {
		if (!sameEven) {
			cout << 1 << endl;
		} else {
			if ((b-a) / 2 % 2 ) {
				cout << 2 << endl;
			} else {
				cout << 3 << endl;
			}
		}
	} else {
		if (sameEven) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	while (n--) {
		solve();
	}
}
