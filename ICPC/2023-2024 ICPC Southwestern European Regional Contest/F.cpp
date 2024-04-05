//
// Created by LL06p on 2024/4/4.
//
#include <bits/stdc++.h>

using namespace std;
using entry = tuple<string, int, array<int, 6>>;

long long getS(entry &e) {
    long long rt = 0;
    rt += get<1>(e) * 10;
    auto &t = get<2>(e);
    sort(t.begin(), t.end());
    rt += accumulate(t.begin()+1, t.end()-1, 0);

    return rt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<entry> arr(n);
    for (auto &i : arr) {
        cin >> get<0>(i) >> get<1>(i);
        for (auto &j : get<2>(i)) {
            cin >> j;
        }
    }
    vector<pair<long long, string>> sortItem(n);
    auto toSort = [] (entry &e)->pair<long long, string> {
        return {getS(e), get<0>(e)};
    };
    transform(arr.begin(), arr.end(), sortItem.begin(), toSort);
    ranges::stable_sort(sortItem, ranges::greater{}, [](auto i) {return i.first;});

    int prvSTeam = 0;
    int curSTeam = 0;
    long long prvS = -1;
    int const maxTeam = 1000;
    for (auto &i : sortItem) {
        if (prvS != i.first) {
            ++prvS = i.first;
            prvSTeam += curSTeam;
            curSTeam = 0;
        }
        ++curSTeam;
        if (prvSTeam + curSTeam <= maxTeam && prvSTeam <= 2) {
            cout << get<1>(i) << ' ' << get<0>(i) << endl;
        }
    }

}