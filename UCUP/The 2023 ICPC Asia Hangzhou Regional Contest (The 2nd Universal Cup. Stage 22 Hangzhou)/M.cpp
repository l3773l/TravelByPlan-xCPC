#include <bits/stdc++.h>

using namespace std;

double compute(long long length, long long x, double avg) {
	return (length + x / avg) / (length + 1);
}

void solve() {
	int n;
	cin >> n;
	vector<long long> arr(n);
	for (auto &i : arr) {
		cin >> i;
	}
	auto mid = min_element(arr.begin(), arr.end());
	auto left = mid -1;
	auto right = mid + 1;
	auto avg1 = accumulate(arr.begin(), right + 1, 0.) / (right - arr.begin() + 1);
	auto avg2 = accumulate(left, arr.end(), 0.) / (arr.end() - left);
	auto avg3 = accumulate(arr.begin(), arr.end(), 0.) / arr.size();
	
	cout << fixed << setprecision(20) << max({avg1, avg2, avg3}) << endl;
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
