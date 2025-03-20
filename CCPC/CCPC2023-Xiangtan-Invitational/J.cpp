#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> strings(n);
    for (auto &i : strings) {
        cin >> i;
    }

    int ans = 0;
    for (int a = 0; a < strings.size(); ++a) {
        auto &aStr = strings[a];

        for (int b = a+1; b <strings.size(); ++b) {
            auto &bStr = strings[b];
            for (int len = 1; len <= min(aStr.length(), bStr.length()); ++len) {
                for (int beg = 0; beg+len <= aStr.length(); ++beg) {
                    auto str = aStr.substr(beg, len);
                    if (bStr.find(str) != string::npos) {
                        ans = max(ans, len);
                    }
                }
            }
        }
    }
    cout << ans << endl;

}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}