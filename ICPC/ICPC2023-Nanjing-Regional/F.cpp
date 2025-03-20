#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i,a,b) for (int i = (a), i##__end = (b); i >= i##__end; --i)

#define pb push_back

const int N = 2e6 + 7;

vector<int> a[N];
set<int> e[N];
int deg[N];

void sol() {
    int n, m;
    cin >> n >> m;

    For (i, 1, m) a[i].clear();
    For (i, 1, n) e[i].clear(), deg[i] = 0;

    For (i, 1, n) {
        int p;
        cin >> p;
        int t;
        For (j, 1, p) cin >> t, a[t].pb(i);
    }

    For (i, 1, m) {
        auto &v = a[i];
        int len = v.size();
        if (len <= 1) continue;
        int to = v.back();
        For (j, 1, len - 1) {
            int f = v[j - 1];
            auto it = e[f].find(to);
            if (it == e[f].end()) e[f].insert(to), deg[to]++;
        }
    }

    queue<int> q;
    int cnt = 1;
    For (i, 1, n) if (!deg[i]) q.push(i);
    vector<int> ans;
    while (!q.empty()) {
        if (q.size() == 1) ++cnt;
        else {
            int t = q.front();
            if (t == cnt) {
                // cout << "repush " << t << endl;
                q.push(t), q.pop();
                continue;
            }
        } 

        int u = q.front(); q.pop();
        // cout << "exact " << u << endl;
        ans.pb(u);
        for (auto v : e[u]) {
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (cnt == n + 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (auto i : ans) cout << i << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}