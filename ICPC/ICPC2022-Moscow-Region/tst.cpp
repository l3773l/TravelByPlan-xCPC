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

int frac[MAXN];

int findmin(int x) {
    int g = -1;
    vector<int> v;
    while (x) v.pb(x % 10), x /= 10;
    int sz = v.size();
    // cout << "sz" << sz << endl;
    // For (i, 1, sz) cout << v[i - 1] << endl;
    For (i, 1, frac[sz]){
        int y = 0;
        For (j, 1, sz) y *= 10, y += v[j - 1];
        if (g == -1) g = y;
        else g = gcd(g, y);
        next_permutation(v.begin(), v.end());
    }
    return g;
}

int f[103];
int main() {
    // freopen("out.txt", "w", stdout);
    // cin >> T;
    T = 1e8;
    frac[0] = 1;
    For (i, 1, 100) frac[i] = frac[i - 1] * i;
    For (i, 1, T) {
        int t = findmin(i);
        if (t <= 81 && f[t] == 0) {
            f[t] = i;
            cout << t << ": " << i << endl;
        }
    }
    cout << "tot:" << endl;
    For (i, 1, 81) cout << i << " " << f[i] << endl;
}
/*
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 0
11 11
12 48
13 0
14 0
15 5055
16 0
17 0
18 288
19 0
20 0
21 7077
22 22
23 0
24 8088
25 0
26 0
27 3699
28 0
29 0
30 0
31 0
32 0
33 33
34 0
35 0
36 48888
37 0
38 0
39 0
40 0
41 0
42 0
43 0
44 44
45 0
46 0
47 0
48 0
49 0
50 0
51 0
52 0
53 0
54 0
55 55
56 0
57 0
58 0
59 0
60 0
61 0
62 0
63 111888
64 0
65 0
66 66
67 0
68 0
69 0
70 0
71 0
72 0
73 0
74 0
75 0
76 0
77 77
78 0
79 0
80 0
81 0*/