#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n, m;
	cin >> n >> m;
	if (n < m) {
		swap(n, m);
	}
	
	cout << m + (n - m + 1) / 2 << endl;
	
}
