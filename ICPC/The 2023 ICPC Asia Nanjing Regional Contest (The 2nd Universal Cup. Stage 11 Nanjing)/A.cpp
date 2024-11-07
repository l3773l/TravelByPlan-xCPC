#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
#define Ford(i,a,b) for (int i = (a), i##__end = (b); i >= i##__end; --i)

#define pb push_back
#define fi first
#define se second 

using pii = pair<int, int>;

const int N = 5e3 + 7;

int n, m;
int ub, db, lb, rb;
int ans;
vector<pii> chk;

int _vis[N], _a[N];

int &a(int x, int y) { return _a[(x - 1) * m + y - 1]; }
int &vis(int x, int y) { return _vis[(x - 1) * m + y - 1]; }

void chmin(int &x, int y) { if (y < x) x = y; }
void chmax(int &x, int y) { if (y > x) x = y; }

void upd(pii f) {
    chk.pb(f);
    chmin(ub, f.fi), chmax(db, f.fi), chmin(lb, f.se), chmax(rb, f.se);
}

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    queue<pii> q;
    chk.clear();
    ub = n, lb = m, db = rb = 1;
    q.push({x, y}); upd({x, y});
    vis(x, y) = 1;
    while (!q.empty()) {
        auto [ci, cj] = q.front(); q.pop();
        For (i, 0, 3) {
            int ni = ci + dx[i], nj = cj + dy[i];
            if (1 <= ni && ni <= n && 1 <= nj && nj <= m && !a(ni, nj) && !vis(ni, nj)) {
                vis(ni, nj) = 1;
                q.push({ni, nj}); upd({ni, nj});
            }
        }
    }

    // cout << "blk: " << endl;
    // for (auto [ci, cj] : chk) {
    //     cout << "(" << ci << ", " << cj << ")" << endl;
    // }
    // cout << "end blk" << endl;

    // cout << "box " << lb << " " << rb << " " << ub << " " << db << endl;
    For (i, 1 - ub, n - db) For (j, 1 - lb, m - rb) {
        if (i == 0 && j == 0) continue;
        bool ok = 0;
        for (auto [ci, cj] : chk) {
            int ni = ci + i, nj = cj + j;
            ok |= a(ni, nj);
        }
        // cout << "chk " << ub + i << " " << lb + j << " " << ok << endl; 
        if (!ok) return;
    }

    ans += chk.size();

    // for (auto [ci, cj] : chk) {
    //     vis(ci, cj) = 2;
    // }
}

void sol() {    
    cin >> n >> m;
    
    fill(_vis, &vis(n, m) + 1, 0);
    
    For (i, 1, n) {
        string s;
        cin >> s;
        int len = s.length();
        For (j, 1, len) {
            a(i, j) = s[j - 1] == 'O';
        }
    }

    ans = 0;

    For (i, 1, n) For (j, 1, m) if (!vis(i, j) && !a(i, j)) dfs(i, j);

    // cout << "ans : ";
    cout << ans << endl;

    // For (i, 1, n) {
    //     For (j, 1, m) cout << (vis(i, j) == 2 ? 'O' : 'x');
    //     cout << endl;
    // }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}