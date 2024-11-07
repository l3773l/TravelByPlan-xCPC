#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> ops(m);
    for (auto &[t, b] : ops) {
        cin >> t >> b;
    }

    sort(begin(ops), end(ops));

    long long prevT = 0;
    long long prevC = 0;
    for (int i=0; i<m; ++i) {
        auto [t, b] = ops[i];
        if (prevC + (t - prevT) != b && (t - prevT - 1) < b) {
            cout << "No" << endl;
            return ;
        }
        prevT = t;
        prevC = b;
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}