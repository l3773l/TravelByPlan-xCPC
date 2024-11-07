#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i,a,b) for (int i = (a), i##__end = (b); i >= i##__end; --i)

#define pb push_back

using ll = long long;

struct I {
    ll maxf, maxg;
    ll sumf, sumg;
    ll lzf, lzg;
};

const int N = 1e5 + 7;

#define lc (u << 1)
#define rc (u << 1 | 1)

I tr[N << 2];

I op(I a, I b) {
    assert(!a.lzf && !b.lzf && !a.lzg && !b.lzg);
    return {max(a.maxf, b.maxf), max(a.maxg, b.maxg), a.sumf + b.sumf, a.sumg + b.sumg, 0, 0};
}

void pull() {
    tr[u] = op(tr[lc], tr[rc]);
}

void build(int u = 1, int l = 1, int r = n) {
    if (l == r) {
        tr[u] = {pre[l], suf[l], pre[l], suf[l], 0, 0}
        return;
    }
    build(lc, l, mid), build(rc, mid + 1, r);
    pull();
}

void sol() {
    cin >> n;
    ll sum = 0;
    For (i, 1, n) cin >> a[i], sum += a[i];

    pre[1] = a[1];
    For (i, 2, n) pre[i] = max(a[i], pre[i - 1]);
    suf[n - 1] = a[n - 1];
    Ford (i, n - 1, 1) suf[i] = max(a[i], suf[i + 1]);
    cin >> q;
    For (i, 1, q) {
        int x; ll v;
        cin >> x >> v;
        sum += v;
        int l = 1, r = n;
        while (l <= r) {
            int suml = qu_max(1, mid), sumr = qu_max(mid, n);
            if (suml < sumr) l = mid + 1;
            else if (suml > sumr) r = mid - 1;
            else {
                ll ans = qu_sum(1, mid) + qu_sum(mid, n) - sum;
                cout << ans << endl;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) sol();
}