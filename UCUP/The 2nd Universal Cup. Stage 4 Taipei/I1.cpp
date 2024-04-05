#include <bits/stdc++.h>
#include <limits>

using namespace std;

struct sQue {

    long long count = 0;
    stack<long long> s; ///< 单调栈
    void Add(long long a) {
        while (!s.empty() && s.top() > a) {
            s.pop(), ++count;
        }
        while (!s.empty() && s.top() == a) s.pop();
        if (a != 0) s.push(a);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> arr;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sQue s;
    for (auto i : arr) {
        s.Add(i);
    }
    sQue s2;
    for (auto i : arr) {
        s.Add(numeric_limits<long long>::max() - i);
    }
    cout << min(s.count + s.s.size(), s2.count-s.s.size()) << endl;
}