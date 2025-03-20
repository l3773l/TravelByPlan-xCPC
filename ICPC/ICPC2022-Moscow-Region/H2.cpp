#include <bits/stdc++.h>

using namespace std;

constexpr char pattern[] = R"(MCM|CXC|XIX|[DLV]|M{1,3}(?!CM)|C{1,3}(?!XC)|X{1,3}(?!IX)|I{1,3})";

regex re{pattern};

int main() {
    int n;
    cin >> n;
    string text;
    cin >> text;
    auto cur = regex_iterator(text.begin(), text.end(), re);
    vector<string> strs;
    for (; cur != decltype(cur){}; ++cur) {
        strs.push_back(cur->str());
    }
    cout << strs.size() << endl;
    for (auto &i : strs) {
        cout << i << endl;
    }
}