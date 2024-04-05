#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i,a,b) for (int i = (a), i##__end = (b); i >= i##__end; --i)
typedef long long ll;
typedef long double lf;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fl(s) s.begin(), s.end()

void cmax2(int &ma1, int &ma2, int v) {
    if (v >= ma1) ma2 = ma1, ma1 = v;
    else if (v >= ma2) ma2 = v; 
}

int hbit(int x) { return x ? (1 << (sizeof(int) * 8 - 1 - __builtin_clz(x))) : 0; }

const int MAXN = 1e5 + 7;

int cnt[MAXN];

int n, a;
void solve() {
    cin >> n;
    int ma1 = 0, ma2 = 0;
    For (i, 1, n) cin >> a, ++cnt[a];
    For (i, 1, n) cmax2(ma1, ma2, cnt[i]);
    // cout << ma1 << " " << ma2  << " " << hbit(ma1 & ma2) << endl;
    int ans = ma1 | ma2 | (max(hbit(ma1 & ma2) - 1, 0));
    cout << ans << endl;
}

int T;
int main() {
    cin >> T;
    For (i, 1, T) {
        if (T != 1) For (i, 1, n) cnt[i] = 0;
        solve();
    }
}