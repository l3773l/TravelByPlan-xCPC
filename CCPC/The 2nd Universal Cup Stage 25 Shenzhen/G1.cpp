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

const int MAXN = 1e3 + 3;
const int MAXM = 6e4 + 3;

int n, m, q, k;
int ha[MAXM], hs[MAXN][MAXM];
string s[MAXN], t;
int ppow[MAXM];

int mul(int x, int y) { return 1ll * x * y % mod; }
int add(int x, int y) { int r = x + y; if (r >= mod) r -= mod; return r; }
int sub(int x, int y) { int r = x - y; if (r < 0) r += mod; return r; }

void hcalc(int *hash, string& str) {
    For (i, 1, m) hash[i] = add(mul(hash[i - 1], p), str[i - 1] - 'a');
}

void pcalc() { ppow[0] = 1; For (i, 1, m) ppow[i] = mul(ppow[i - 1], p); }

int hsub(int *hash, int i, int j) { return sub(hash[j], mul(hash[i - 1], ppow[j - i + 1])); }

int find(int bef, int *ha1, int *ha2) {
    int ans = -1;
    int l = bef + 1, r = m;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int v1 = hsub(ha1, bef + 1, mid),
            v2 = hsub(ha2, bef + 1, mid);
        // cout << l << " " << r << " " << v1 << " " << v2 << endl;
        if (v1 != v2) r = mid - 1, ans = mid; else l = mid + 1; 
    }
    // cout << __func__ << " " << ans << endl;
    return ans;
}

bool comp(int *ha1, int *ha2, string &s1, string &s2) {
    // cout << "comp: " << s1 << " " << s2 << endl;
    int bef = 0;
    For (i, 1, k + 1) {
        bef = find(bef, ha1, ha2);
        if (bef == -1) return 1;
    }
    return 0;
}

int main() {
    cin >> n >> q >> m >> k;
    pcalc();
    For (i, 1, n) cin >> s[i], hcalc(hs[i], s[i]);
    For (i, 1, q) {
        cin >> t;
        hcalc(ha, t);
        int ans = 0;
        For (j, 1, n) ans += comp(hs[j], ha, s[j], t);
        cout << ans << endl;
    }
}
