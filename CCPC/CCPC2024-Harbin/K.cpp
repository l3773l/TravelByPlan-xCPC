#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define pb push_back

using ll = long long;

const int N = 1e5 + 7;

struct ty_t {
    ll w, l, r;
} a[N];

void chmax(ll &x, ll y) {
    if (y > x) x = y;
}

int s[N];
ll v[N];

int main() {
    int n, m;
    cin >> n >> m;
    For (i, 1, n) cin >> a[i].w >> a[i].l >> a[i].r;
    sort(a + 1, a + n + 1, [&](ty_t a, ty_t b) {
        return a.w == b.w ? a.l > b.l : a.w > b.w;
    });

    int wm = a[1].w;
    int lm = a[1].l, rm = a[1].r;



    ll L = 0;
    For (i, 2, n) {
        L += a[i].l;
    }

    ll ans = 0;

    ll ans1 = (m - L) * wm;
    For (i, 2, n) ans1 += a[i].l * a[i].w;
    chmax(ans, ans1);

    cout << ans1 << endl;

    ll bans = 0;
    For (i, 1, n) {
        ll r = a[i].r;
        if (i > 1) L -= a[i].l;
        if (r <= m - L) {
            bans += r * a[i].w;
            chmax(ans, bans);
            m -= a[i].r;
        } else {
            cout << "tail " << i + 1 << endl;
            ll res = a[i].r - (m - L);

            bans += a[i].w * (m - L);

            For (j, i + 1, n) bans += a[i].w * a[i].l;
            
            For (j, i + 1, n) s[j] = s[j - 1] + (a[i].r - a[i].l), v[j] = v[j - 1] + a[i].w * (a[i].r - a[i].l);

            ll wi = a[i].w;

            For (j, i + 1, n) {
                ll l = a[j].l, wj = a[j].w;
                if (l <= res) {
                    chmax(ans, bans + l * wi - l * wj); 
                } else if (i + 1 == j) {
                    chmax(ans, bans + res * (wi - wj));
                } else {
                    ll t = l - res;
                    int pos = upper_bound(s + i + 1, s + j, t) - s - 1;
                    ll bbans = bans + res * (wi - wj);
                    if (pos == 0) {
                        chmax(ans, bbans + t * (a[i + 1].w - wj));
                    } else {
                        chmax(ans, bbans + v[pos] + a[pos + 1].w * (t - s[pos]) - wj * t);
                    }
                }
                cout << j << " " << ans << endl;
            }
        }
    }

    cout << ans << endl;
}