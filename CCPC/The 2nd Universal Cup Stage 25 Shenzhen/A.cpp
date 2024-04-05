#include <bits/stdc++.h>

using namespace std;

struct searcher {
    vector<pair<int, int>> numbers;
    set<int> allPos;
    vector<pair<int, int>> ans;
    searcher(int n): numbers(n) {
        for (int i=0; i<n; ++i) {
            numbers[i].second = i+1;
            allPos.insert(i+1);
        }
    }
    // 处理矩形， 要去输入的区域的基线值与其他区域不同
    void solve(int beg, int sen, int baseLine) {
        if (sen - beg == 0) {
            return;
        }
        auto minOne = numbers[sen-1].first;
        while (baseLine < minOne) {
            ans.emplace_back(1, baseLine++);
        }
        if (numbers[beg].first == minOne) {
            return ;
        }
        auto midPoint = (sen + beg) / 2;
        while (midPoint > beg && numbers[midPoint-1].first == minOne) {
            --midPoint;
        }
        for (int cur=beg; cur < midPoint; ++cur) {
            ans.emplace_back(2, numbers[cur].second);
        }
        solve(beg, midPoint, baseLine+1);
        solve(midPoint, sen, baseLine);

    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    searcher s(n);
    for (auto &i : s.numbers) {
        cin >> i.first;
    }
    sort(s.numbers.begin(), s.numbers.end(), greater<pair<int, int>>{});
    s.solve(0, s.numbers.size(), 0);
    cout << s.ans.size() << endl;
    for (auto i : s.ans) {
        cout << i.first << ' ' << i.second << '\n';
    }
}