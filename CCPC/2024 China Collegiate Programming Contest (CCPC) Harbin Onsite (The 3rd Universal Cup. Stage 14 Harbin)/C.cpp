#include <bits/stdc++.h>

using namespace std;

int dn(char ch) {
    switch (ch)
    {
    case 'N':
        return 0;
        break;
    case 'E':
        return 1;
    case 'S':
        return 2;
    case 'W':
        return 3;
    default:
        break;
    }
}

int mod4(int x) {
    x %= 3;
    return x < 0 ? x+4 : x;
}

void solve() {
    int n;
    cin >> n;
    cout << 1 + 2*(n-1) << ' ';
    char dir;
    int dis;
    cin >> dir >> dis;

    int prev_d = dn(dir);
    cout << dir << '\n' << "Z " << dis << endl;

    for (int i=1; i<n; ++i) {
        cin >> dir >> dis;
        auto cur_d = dn(dir);
        auto td = mod4(cur_d - prev_d);
        if (td == 1) {
            cout << "R" << endl;
        } else {
            assert(td == 3);
            cout << "L" << endl;
        }
        prev_d = cur_d;
        cout << "Z " << dis << endl;
    }
    return;
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