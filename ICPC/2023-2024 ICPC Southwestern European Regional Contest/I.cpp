//
// Created by LL06p on 2024/4/4.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int aN, bN;
    cin >> aN >> bN;
    vector<unsigned long long> a(aN);
    vector<unsigned long long> b(bN);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto  &i : b) {
        cin >> i;
    }

    unsigned long long aSum = 0, bSum = 0;
    for (auto i : a) {
        aSum += (i + 1);
    }
    for(auto i : b) {
        bSum += (i +1);
    }
    if (aSum == bSum) {
        cout << "TIED" << endl;
    } else if (aSum > bSum) {
        cout << "ALICE" << endl;
    } else {
        cout << "BOB" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}