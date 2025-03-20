#include <bits/stdc++.h>

using namespace std;

void judge(int n, int m, int k) {
    bool isOk = true;
    if (k < m) {
        isOk = false;
    }
    if (k <= 1) {
        isOk = false;
    }
    if (m == 0) {
        isOk == false;
    }
    

    if (isOk) {
        return ;
    } else {
        cout << "NO";
        exit(0);
    }

}

void solve(int n, int m, int k) {
    // length := k
    // sameBlock := m
    // number := n

    judge(n, m, k);
    auto spanLength = m;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    solve(n, m, k);
    return 0;
}