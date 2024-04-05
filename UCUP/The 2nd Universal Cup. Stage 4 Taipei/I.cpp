#include <bits/stdc++.h>

using namespace std;

struct sQue {

    long long count = 0;
    stack<long long> s; ///< 单调栈
    void Add(long long a) {
        if (a == 0) {
            while (!s.empty()) {
                s.pop();
            }
        } else {
            if (s.empty()) {
                ++count;
                s.push(a);
            } else {
                if (s.top() == a) {
                    s.push(a);
                } else if (s.top() < a) {
                    ++count;
                    s.push(a);
                } else {
                    while (!s.empty() && s.top() > a) {
                        s.pop();
                    }
                    Add(a);
                }
            }
        }
        
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
        s2.Add(numeric_limits<long long>::max()-i);
    }
    cout << min(s.count, s2.count) << endl;
}