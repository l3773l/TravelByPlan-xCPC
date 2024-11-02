#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<std::pair<long long, long long>> sta(m);
    for (auto &i : a) {
        cin >> i;
    }

    for (auto &[x, t] : sta) {
        cin >> x >> t;
    }
    ranges::sort(sta);

    auto sum_a = accumulate(begin(a), end(a), 0LL);
    long long d = 0;
    long long counter = 0;

    long long prev_p = 0;
    for (int i=0; i<m; ++i) {
        if (sum_a - d < sta[i].first - prev_p) {
            counter += sum_a - d;
            d = sum_a;
            break;
        } else {
            d += sta[i].first - prev_p;
            counter += sta[i].first - prev_p;
            prev_p = sta[i].first;

            d -= min(d, a[sta[i].second-1]);
        }
    }
    counter += sum_a - d;

    cout << counter << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}