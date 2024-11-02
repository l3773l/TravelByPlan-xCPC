#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

using ll = long long;

#define fi first 
#define se second

const int N = 2e5 + 7;

ll a[N];
pair<ll, ll> x[N];

void sol() {
    int n, m;
    cin >> n >> m;
    ll f = 0;
    For (i, 1, n) cin >> a[i], f += a[i];
    ll sum = f;
    For (i, 1, m) cin >> x[i].fi >> x[i].se;
    sort(x + 1, x + m + 1);

    For (i, 1, m) {
        ll dx = x[i].fi - x[i - 1].fi;
        if (f < dx) {
            cout << x[i - 1].fi + f << endl;
            return;
        } else {
            f = min(sum, f - dx + a[x[i].se]);
        }
    }

    cout << x[m].fi + f << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}