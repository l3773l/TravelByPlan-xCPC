#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a;
    string b;
    cin >> a >> b;
    vector<int> arr{0};
    for (int i=0; i<n; ++i) {
        int diff = b[i] - a[i];
        if (diff < 0) {
            diff += 26;
        }
        arr.push_back(diff);
    }
    vector<int> diff;
    adjacent_difference(arr.begin(), arr.end(), back_insert_iterator(diff));
    cout << count_if(diff.begin(), diff.end(), [](int i) {return i!=0;}) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}