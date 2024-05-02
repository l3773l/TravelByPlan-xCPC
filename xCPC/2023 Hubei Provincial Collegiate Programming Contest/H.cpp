#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int cnt[maxn];
using ll = long long;
long long mod = 998244353L;
int mul(int x, int y) { 
	return 1ll * x * y % mod;
}

int add(int x, int y) {
	ll r = x + y;
	if (r >= mod) r -= mod;
	return r;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		cnt[u]++;cnt[v]++;
	}
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		mp[cnt[i]]++;
	}
	vector<pair<int,int> > vec;
	for(auto x:mp){
		//first  is the deg of node , second is the number 
		vec.push_back({x.first,x.second});
	}
	long long ans = 0;
	for(int i=0;i<vec.size();i++){
		for(int j=i+1;j<vec.size();j++){
			int u = vec[i].first, v = vec[j].first;
			int bit = mul(mul((u ^ v) % mod, (u | v) % mod), (u & v) % mod);
			bit = mul(bit, mul(vec[i].second, vec[j].second));
			ans = add(ans, bit); 
		}
	}
	printf("%lld\n",ans);
	return 0;
}
