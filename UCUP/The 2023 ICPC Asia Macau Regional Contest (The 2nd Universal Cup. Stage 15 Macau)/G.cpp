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
int a[maxn];
int vis_t[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	queue<pair<int,int> > que;
	que.push({0,0});
	for(int i=1;i<=n;i++) vis_t[i] = -1;
	while(!que.empty()){
		int pos = que.front().first;
		int ti = que.front().second;
		if(vis_t[])
	}
	return 0;
}

