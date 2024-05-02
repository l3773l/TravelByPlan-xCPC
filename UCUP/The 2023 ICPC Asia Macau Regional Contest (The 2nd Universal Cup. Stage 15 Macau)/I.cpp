#include <bits/stdc++.h>

#define NDEBUG 

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	while(T--){
		ll a,b,m;
		cin>>a>>b>>m;
		ll cnt;
		if(2*b<=a){
			//use b to refresh
			assert(cout << "CASE 1" << endl);
			cnt = 2 + m/b;
		}
		else if (b<=a) {
			assert(cout << "CASE 2" << endl);
			cnt = 2 + m/a * 2 + (m%a) / b;
		}
		else /*b > a*/ {
			assert(cout << "CASE 3" << endl);
			long long cnt2 = 2;
				auto len = (b/a+1)*a;
				auto times = m / len;
				cnt2 += times * (b/a+2);
				auto remain = m % len;
				cnt2 += remain / a;
				cnt2 += remain / b;
				auto cnt3 = 2 + (b/a+1) * (m/b) + (m%b/a);
			cnt = max(cnt2, cnt3);
		}
		cout<<cnt*160<<"\n";
		assert(cout << flush);
	}	
	return 0;
}
/*
2
60 200 960
60 185 905
*/

