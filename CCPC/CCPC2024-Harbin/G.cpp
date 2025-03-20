#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define pb push_back

using ll = long long;

const int N = 2e5 + 7;
const int M = 5e5 + 7;

int vis[N], busy[N];

vector<int> e[M];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    // cout << "enter " << x << endl;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 1;
        // cout << "vis " << u << endl;
        for (auto v : e[u]) {
            if (!vis[v] && !busy[v]) {
                q.push(v);
            }
        }
    }
}

queue<queue<int>> out;

void bfs1(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = 2;


    while (!q.empty()) {
        int u = q.front(); q.pop();
        queue<int> tout;
        tout.push(u);
        for (auto v : e[u]) {
            if (vis[v] != 2) {
                if (!busy[v]) q.push(v);
                tout.push(v);
                vis[v] = 2;
            }
        }
        if (tout.size() > 1) out.emplace(tout);
    }
}

void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    int t;
    For (i, 1, k) cin >> t, busy[t] = 1;
    // cout << "okok" << endl;
    For (i, 1, m) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v), e[v].pb(u);
    } 
    // cout << "ok" << endl;

    bool flag = 0;
    For (i, 1, n) if (!vis[i] && !busy[i]) {
        if (flag) {
            cout << "No" << endl;
            return;
        }
        bfs(i);
        flag = 1;
    }

    bool ok = 1;
    For (i, 1, n) {
        if (busy[i]) {
            bool t = 0;
            for (auto v : e[i]) {
                t |= !busy[v];
            }
            ok &= t;
        }
    }

    if (!ok) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    For (i, 1, n) if (!busy[i]) {
        bfs1(i);
        break;
    }

    cout << out.size() << endl;
    while (!out.empty()) {
        auto &q = out.front();
        cout << q.front() << " ";
        q.pop();
        cout << q.size() << " ";
        while (!q.empty()) {
            int v = q.front(); q.pop();
            cout << v << " ";
        }
        cout << endl;
        out.pop();
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--) sol();
}