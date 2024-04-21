#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)

int ask(int u, int v) {
	cout << "? " << u << " " << v << endl;
	cout.flush();
	int n;
	cin >> n;
	return n;
}

#define ye cout << "! 2" << endl << flush
#define no cout << "! 1" << endl << flush
int n;
int w, x;
void sol() {
	cin >> n;
	For (i, 1, n / 2) {
		int r = ask(2 * i - 1, 2 * i);
		if (r) {
			int u = 2 * i - 1, v = 2 * i;
			if (u == 1) {
				w = 3, x = 4;
			} else w = 1, x = 2;
			if (ask(u, w) && ask(u, x)) ye;
			else if (ask(v, w) && ask(v, x)) ye;
			else no;
			return;
		}
	}
	if (n & 1){
		int u = n;
		if (ask(n, 1) && ask(n, 2) && ask(n, 3)) ye;
		else no;
	} else no;
}

int t;
int main() {
	cin >> t;
	while (t--) sol();
}
