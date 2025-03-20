#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    int opCount = 0;
    while (str.size() / 2 < m) {
        ++opCount;
        string newStr;
        auto backIn = back_inserter(newStr);
        auto beg = str.begin();
        auto sen = str.end();
        auto mid = beg + (sen - beg) / 2;
        copy(beg, mid, backIn);
        copy(beg, sen, backIn);
        transform(mid, sen, backIn, [](char i) { auto offset = i - 'a'; ++offset %= 26; return 'a' + offset;});
        str = std::move(newStr);
    }

    string cache{};
    copy(str.end() - m, str.end(), back_inserter(cache));

    for (auto &i : cache) {
        auto offset = i - 'a';
        offset += 16;
        offset -= opCount;  
        while (offset < 0) {
            offset += 26;
        }
        offset %= 26;
        i = offset + 'a';
    }

    cout << cache;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();
}