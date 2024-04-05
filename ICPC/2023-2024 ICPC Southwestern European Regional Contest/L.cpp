//
// Created by LL06p on 2024/4/4.
//
#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), i##__end = (b); i <= i##__end; ++i)

const int MAXN = 3e5 + 7;

int a[MAXN], b[MAXN];
int k, n;
using qu = queue<int>;
int c[7];
int c22;
qu l[7], l22;
vector<int> a1, a2, a3;
#define pb push_back
#define pu1(x, y) (x.pb(y))
#define pu2(x, y) (x.pb(y), x.pb(y))
#define pu3(x, y) (x.pb(y), x.pb(y), x.pb(y))
auto ge(queue<int> &a) { int x = a.front(); a.pop(); return x; }
int main() {
    cin >> k >> n;
    For (i, 1, k) cin >> a[i];
    For (i, 1, k) cin >> b[i];
    For (i, 1, k) {
        if (a[i] == 2 && b[i] == 2) c22++, l22.push(i);
        else c[a[i] + b[i]]++, l[a[i] + b[i]].push(i);
    }

    int t1 = c[4] / 2; c[4] %= 2;
    int t2 = c22 / 3; c22 %= 3;
    int t = min(t2, t1);
    if (t) {
        For (i, 1, t) {
            int b31 = ge(l[4]), b32 = ge(l[4]);
            int sq1 = ge(l22), sq2 = ge(l22), sq3 = ge(l22);
            pu3(a1, b31), pu3(a1, b32);
            pu2(a2, sq1), pu2(a2, sq2), pu2(a2, sq3);
            pu2(a3, sq1), pu2(a3, sq2), pu2(a3, sq3);
        }
        t2 -= t;
        t1 -= t;
    }
    c[4] += t1 * 2;
    c22 += t2 * 3;

    if (c22 > 0) {
        if (c[4] == 1) {
            if (c22 == 1) {
                goto nxt;
            }
            int b3 = ge(l[4]);
            int sq1 = ge(l22), sq2 = ge(l22);
            pu3(a1, b3);
            if (c[3] >= 1) {
                int t = ge(l[3]);
                pu2(a1, t);
            } else {
                int t1 = ge(l[2]), t2 = ge(l[2]);
                pu1(a1, t1), pu1(a1, t2);
            }
            pu2(a2, sq1), pu2(a2, sq2);
            pu2(a3, sq1), pu2(a3, sq2);
        }
    }

    nxt:

    {
        int t = min(c22, c[3]);
        if (t) {
            For (i, 1, t) {
                int sq = l22.front();
                l22.pop();
                int x2 = l[3].front();
                l[3].pop();
                pu2(a1, x2);
                pu2(a2, sq);
                pu2(a3, sq);
            }
            c22 -= t, c[3] -= t;
        }
    }

    {
        int t1 = c[2] / 2;
        c[2] %= 2;
        int t = min(c22, t1);
        if (t) {
            For (i, 1, t) {
                int sq = l22.front();
                l22.pop();
                int x1 = ge(l[2]), x2 = ge(l[2]);
                pu1(a1, x1), pu1(a1, x2);
                pu2(a2, sq);
                pu2(a3, sq);
            }
            c22 -= t;
            t1 -= t;
        }
        c[2] += t1 * 2;
    }

    assert(c22 == 0);
    {
        int t = c[3] / 3; c[3] %= 3;
        For (i, 1, t) {
            int x = ge(l[3]), y = ge(l[3]), z = ge(l[3]);
            pu2(a1, x), pu2(a2, y), pu2(a3, z);
        }
    }

    if (c[3] == 1) {
        int g3 = ge(l[3]);
        int g2 = ge(l[2]);
        pu1(a1, g3), pu1(a2, g3), pu1(a3, g2);
    } else if (c[3] == 2) {
        int g31 = ge(l[3]), g32 = ge(l[3]);
        int g21 = ge(l[2]), g22 = ge(l[2]);
        pu2(a1, g31), pu2(a2, g32), pu1(a3, g21), pu1(a3, g22);
    } else assert(0);

    while (c[4]) {
        int g = ge(l[4]);
        pu1(a1, g), pu1(a2, g), pu1(a3, g);
        c[4]--;
    }

    while (c[5]) {
        int g = ge(l[5]);
        pu2(a1, g), pu2(a2, g), pu2(a3, g);
        c[5]--;
    }

    while (c[6]) {
        int g = ge(l[6]);
        pu3(a1, g), pu3(a2, g), pu3(a3, g);
        c[6]--;
    }

    for (auto i : a1) cout << i << " ";
    cout << endl;
    for (auto i : a2) cout << i << " ";
    cout << endl;
    for (auto i : a3) cout << i << " ";
    cout << endl;
}