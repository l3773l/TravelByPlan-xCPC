#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n <= 3) {
        cout << -1;
    } else {
        cout << n+1 << endl;
        for (int i=1; i<=n-2; ++i) {
            cout << i << ' ' << i+1 << endl;
        }
        cout << n - 1 << ' ' << 1 << endl;
        cout << 1 << ' ' << n << endl;
        cout << n << ' ' << 2 << endl;
    }

    return 0;
}