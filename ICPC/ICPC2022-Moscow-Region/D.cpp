#include <bits/stdc++.h>

using namespace std;

using lf = long double;
using ll = long long;
int n, m, T;

#define For(i, a, b) for (int i = (a), i##__end = (b); i <= i##__end; ++i)
#define pb push_back
#define fi first 
#define se second

const int MAXN = 5e5 + 7;

int Min[MAXN];
set<int> s[MAXN];

int seq[MAXN];

void pd(int d0) {
    int down = d0;
    seq[1] = d0;
    For (i, 2, n) {
        if (s[i].find(down) == s[i].end()) {
            // cout << down <<  " not hit " << i << endl;
            down = Min[i];
        }
        // } else cout << down << " hit " << i << endl;
        seq[i] = down;
    }
    if (s[1].find(down) == s[1].end() || d0 == down) {
        // cout << down <<  " not hit " << 1 << endl;
        For (i, 1, n) cout << seq[i] << " ";
        cout << endl;
    } else pd(down);
}

int t, k;
int main() {
    cin >> n;
    For (i, 1, n) {
        cin >> k;
        Min[i] = INT_MAX;
        For (j, 1, k) {
            cin >> t;
            s[i].insert(t);
            Min[i] = min(Min[i], t);
        }
        // cout << Min[i] << endl;
    }
    pd(Min[1]);
}