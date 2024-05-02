#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<long long> grid(n);
	for (auto &i : grid) {
		cin >> i;
	}
	vector<long long> resource(n);
	partial_sum(grid.begin(), grid.end(), resource.begin());
	if (resource.front() < 0 || resource.back() < 0 ) {
		cout << -1;
		return 0;
	} else {
		long long time = 0;
		long long pSumR = 0;
		long long pMaxR = resource.front();
		for (auto i : resource) {
			pSumR += i;
			if (pSumR < 0) {
				if (pMaxR == 0) {
					cout << -1;
					return 0;
				}
				auto pTime = (-pSumR + pMaxR - 1) / pMaxR;
				auto pR = pTime * pMaxR;
				pSumR += pR;
				time += pTime;
			}
			pMaxR = max(pMaxR, i);
			time ++;
		}
		cout << time << endl;
		return 0;
	}
}
