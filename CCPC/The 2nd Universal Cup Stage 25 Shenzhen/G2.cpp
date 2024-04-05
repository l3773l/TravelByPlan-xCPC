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

const int p = 131;
const int mod = 1e9 + 7;

const int MAXN = 300 + 3;
const int MAXM = 6e4 + 3;

int bs, bc;
int hs[MAXN][MAXM], ha[MAXM];
string s[MAXN];
string t;

int k;
int n, m, q;

void hcalc(int *hash, string& str) {
    For (i, 1, m) hash[i] = (hash[i - 1] * p % mod + str[i - 1] - 'a') % mod;
}

bool comp(int *ha1, int *ha2, string &s1, string &s2) {
    int l = 0, r = 0;
    int ret = 0;
    For (j, 1, bc) {
        l = r + 1, r = min(r + bs, m);
        int v1 = ha1[r] - ha1[l - 1],
            v2 = ha2[r] - ha2[l - 1];
        if (v1 != v2)
            For (k, l, r) ret += s1[k - 1] != s2[k - 1]; 
        // cout << __func__ << s1 << " " <<  v1 << " " << v2 << endl;
    }
    return ret <= k;
}

int main() {
    cin >> n >> q >> m >> k;
    bs = floor(sqrt(m));
    bc = (m + bs - 1) / bs;
    // For (i, 1, m) bel[i] = (i - 1) / bs + 1;
    For (i, 1, n) {
        cin >> s[i];
        hcalc(hs[i], s[i]);
    }
    For (i, 1, q) {
        cin >> t;
        hcalc(ha, t);
        int ans = 0;
        For (j, 1, n) ans += comp(hs[j], ha, s[j], t); 
        cout << ans << endl;
    }
}