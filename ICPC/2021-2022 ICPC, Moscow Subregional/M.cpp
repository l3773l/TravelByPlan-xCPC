#include <bits/stdc++.h>

using namespace std;

using lf = long double;
using ll = long long;
int n, m, T;

#define For(i, a, b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
#define pb push_back
#define fi first 
#define se second
const int MAXN = 2e3 + 7;

lf dist[MAXN];
bool st[MAXN];
using pr = pair<lf, int>;
priority_queue<pr, vector<pr>, greater<pr>> heap;
vector<pr> w[MAXN];

int u, v;
lf l, c;
int main() {
    cin >> n >> m >> T;
    For (i, 1, m) {
        cin >> u >> v >> l >> c;
        lf cw = sqrtl(l) * sqrtl(c);
        w[u].pb({cw, v}), w[v].pb({cw, u});
    }

    auto inf = numeric_limits<long double>::max() / 3;
    fill(dist + 1, dist + n + 1, inf);
    dist[1] = 0; 
    // For (i, 1, n) cout << dist[i] << " ";
    // cout << endl;
    heap.push({0, 1});
    while (heap.size()) {
        auto x = heap.top(); heap.pop();
        auto t = x.se;
        auto dis = x.fi;

        int sz = w[t].size();
        For (j, 1, sz) {
            int to = w[t][j - 1].se;
            auto cw = w[t][j - 1].fi;
            // cout << t << " " << to << " " << cw << " " << dis << " " << (dist[to] > dis + cw) << endl;
            if (dist[to] > dis + cw) dist[to] = dis + cw, heap.push({dist[to], to});
        }
        st[t] = true;
        
        // For (j, 1, n) cout << dist[j] << " ";
        // cout << endl;
    }

    assert (dist[n] != inf);
    cout << fixed << setprecision(10) <<  dist[n] * dist[n] / T << endl;
}