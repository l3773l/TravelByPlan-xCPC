#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
using ll = long long;

const int N = 1e6 + 7;

void chmax(int &x, int v) {
	if (x < v) x = v;
}

int n;
char c[N];
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	int a;
	int r = 0;
	For (i, 1, 2 * n + 2) {
		cin >> a;
		if (i <= 2) {
			continue;
		}
		if (i & 1) {
			int j = i / 2;
			chmax(r, j);
			if (!c[j]) {
				if (j == 1) c[j] = 'a';
				else c[j] = c[j - 1] == 'a' ? 'b' : 'a';
			}
			int len = a / 2 - 1;
			if (len) {
				For (k, max(1, r - j + 1), len) c[j + k] = c[j - k];
				chmax(r, j + len);
			}
		} else {
			int len = a / 2;
			int j = (i - 1) / 2;
			chmax(r, j);
//			cout << i << "-:" << len << " " << j << endl;
			For (k, max(1, r - j + 1), len) c[j + k] = c[j - k + 1];
			chmax(r, j + len - 1);
		}
//		cout << i << ":" << endl;
//		For (i, 1, n) cout << c[i];
//		cout << endl;
	}
	For (i, 1, n) cout << c[i];
	cout << endl;
}
