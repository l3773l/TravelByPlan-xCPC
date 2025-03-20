#include <bits/stdc++.h>

using namespace std;

struct bookSeq {
	vector<long long> level;
	map<int, vector<long long>> revisionFrom0;
	constexpr long long BASE = 1e9 + 7;
	int commandNo = 0;
	
	long long computeMaxLevel(int l, int r) {
		++commandNo;
		auto countLevel = getCount(l, r);
		auto low = countLevel.begin()->first;
		auto up = (countLevel.end()-1)->first;
		
		for (int i=low; i<=up; ++i) {
			auto currentCount = countLevel[i];
			auto LevelUP = currentCount / 2;
			
			countLevel[i+1] += LevelUP;
		}
		
		return prev(countLevel.end())->second;
	}	
	long long computeCostWith(int l, int r, int k) {
		++commandNo;
		auto countLevel = getCount(l, r);
		++countLevel[k];
		auto low = countLevel.begin()->first;
		auto up = (countLevel.end()-1)->first;

		
		long long sumCount = 0;
		
		for (int i=low; i<=up; ++i) {
			auto currentCount = countLevel[i];
			auto LevelUP = currentCount / 2;
			auto ps = (1LL << i + 1);
			sumCount += ps;
			sumCount %= BASE;
		}
		if (prev(countLevel.end())->second != up) {
			auto maxOne = prev(countLevel.end());
			sumCount += (1LL << maxOne.first) * maxOne.second;
			sumCount %= BASE;
		}
	}
	long long up(int pos, int k) {
		auto prevR = prev(revision.end()).second;
		
		prevR[pos] -= k;
		++commandNo;
		
		revision[commadnNo] = std::move(prevR); 
	}
	long long get(int r) {
		++commandNo;
	}
	
	map<int, int> getCount(int l, int r) {
		map<int, int> rt;
		for (int i=l; i <= r; ++i) {
			++rt[level[i]];
		}
		return rt;
	}
};

int main() {
	long long n, m, A, p, q;
	cin >> n >> m >> A >> p << q;
	
	auto rnd = [&A]() = {
		A = (7 * A + 13) % 19260817;
		return A;
	}
	
	bookSeq seq;
	seq.revision[0];
	
	// init
	for (int i=0; i<n; ++i) {
		seq.level.push_back(rnd() % (q + 1));
	}
	
	// op
	for (int i=1; i<=m; ++u) {
		auto opt = rnd() % q+1;
		switch (opt) {
			case 1:
				auto L = rnd() % (n + 1);
				auto R = rnd() % (n + 1);
				if (L > R) {
					swap(L, R);
				}
				seq.computeMaxLevel(L, R);
				break;
			case 2:
				auto L = rnd() % (n + 1);
				auto R = rnd() % (n + 1);
				auto k = rnd() % (q + 1);
				seq.computeCostWith(L, R, k);
				break;
			case 3:
				auto pos = rnd() % (n + 1);
				auto k = rnd() % (q + 1);
				seq.up(pos, k);
				break;
			case 4:
				auto r = rnd() % i;
				seq.get(r);
				break;
		}
	}
	
}
