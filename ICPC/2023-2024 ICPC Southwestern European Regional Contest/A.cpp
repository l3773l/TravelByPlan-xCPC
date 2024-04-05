//
// Created by LL06p on 2024/4/4.
//
#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b) for(int i = (a), i##__end = (b); i <= i##__end; ++i)

const int MAXN = 1e5 + 7;

int ans = -1;
int ord[] = {-1, 1, 2, 3, 4, 5};
int tmp[99];

using pii = pair<int, int>;
pii a[MAXN];

bool cmp(pii a, pii b) {
    return ord[a.first] == ord[b.first] ? a.second < b.second : ord[a.first] < ord[b.first];
}

pii f[MAXN];


int n;
int lis() {
    fill(f, f + n + 1, pii{5, INT_MAX});
    auto mx = f[0];
    For (i, 0, n - 1) * upper_bound(f, f + n, a[i], cmp) = a[i];
    int ans = 0;
    while (f[ans] != mx) ++ans;
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    tmp['S'] = 1, tmp['W'] = 2, tmp['E'] = 3, tmp['R'] = 4, tmp['C'] = 5;

    cin >> n;
    char c;
    int id;
    For (i, 0, n - 1) {
        cin >> c;
        cin >> id;
//        cout << c  << " " << id << endl;
        a[i] = {tmp[c], id};
    }

    For (i, 1, 4 * 3 * 2) {
        // cout << "ord: ";
        // For (j, 1, 4) cout << ord[j] << " ";
        // cout << endl;
        int t = lis();
        // cout << t << endl;
        ans = max(ans, t);
        // cout << "ans: " << ans << endl;
        next_permutation(ord + 1, ord + 4 + 1);
    }

    cout << n - ans << endl;
}