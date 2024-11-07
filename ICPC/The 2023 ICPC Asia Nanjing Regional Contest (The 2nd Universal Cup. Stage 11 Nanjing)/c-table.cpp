#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << ULLONG_MAX << endl;
    size_t p, m;
    cin >> p;
    for (size_t i=1; i<100; i+=1) {
        cout << format("K={} g={}", i, ((1+i*p)^(p-1))) << endl;
    }
    cout << endl;
}